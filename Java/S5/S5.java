/**
 * Author: Qzlzdy
 * Version: S5
 * Date: 2017-3-18
 * Description: Compiler
 * S2新增功能
 * （1）支持减法和除法操作
 * （2）支持空语句
 * （3）支持复合语句
 * （4）支持print语句
 * （5）支持源程序中的单行注释
 * S3新增功能
 * （1）println允许0个参数
 * （2）print和println语句带1个字符串的参数
 * （3）支持一元加和减
 * （4）支持级联赋值
 * （5）支持readint语句
 * （6）单词符号踪迹的生成为可选项
 * （7）修复部分BUG
 * S4新增功能
 * （1）支持while，if，if-else，do-while控制语句
 * （2）进行整数常量范围检测
 * S5新增功能
 * （1）函数定义和函数调用
 * （2）参数传递但不检查实参与形参相容性
 * （3）全局和局部的int变量，初始化和不初始化二者都有
 * 源语言文法：
 * program: programUnitList <EOF>
 * programUnitList: programUnit programUnitList | λ
 * programUnit: externDeclaration | globalDeclaration | funcationDefinition
 * externDeclaration: "extern" "int" <ID> ("," <ID>)* ";"
 * golbalDeclaration: "int" global ("," golbal)* ";"
 * global: <ID> ("=" ("+" | "-")? <UNSIGNED>)?
 * funcationDefinition: "void" <ID> "(" (parameterList)? ")" "{" localDeclarations statementList "}"
 * parameterList: parameter parameterR
 * parameter: "int" <ID>
 * parameterR: "," parameter parameterR
 * localDeclarations: ("int" local ("," local)* ";")*
 * local: <ID> ("=" ("+" | "-")? <UNSIGNED>)
 * statementList: statement statementList | λ
 * statement: asignmentStatement | funcationCall | printlnStatement |printStatement
 *	| nullStatement | compoundStatement | readintStatement | whileStatement | ifStatement
 *	| doWhileStatement
 * assignmentStatement: <ID> "=" assignmentTail
 * assignmentTail: <ID> "=" assignmentTail | expr ";"
 * printlnStatement: "println" "(" (printArg | λ) ")" ";"
 * printStatement: "print" "(" printArg ")" ";"
 * printArg: expr | <STRING>
 * nullStatement: ";"
 * compoundStatement: "{" compoundList "}"
 * compoundList: statement compoundList | λ
 * readintStatement: "readint" "(" <ID> ")" ";"
 * whileStatement: "while" "(" expr ")" statement
 * ifStatement: "if" "(" expr")" statement elsePart
 * elsePart: "else" statement | λ
 * doWhileStatement: "do" statement "while" "(" expr ")" ";"
 * funcationCall: <ID> "(" (argumentList)? ")" ";"
 * argumentList: expr ("," expr)*
 * expr: term termList
 * termList: "+" term termList | "-" term termList | λ
 * term: factor factorList
 * factorList: "*" factor factorList | "/" factor factorList | λ
 * factor: <UNSIGNED> | <ID> | "+" factor | "(" expr ")"
 *	| "-" (<UNSIGNED> | <ID> | ("+")+ ("-" factor | factor) | "-" factor | "(" expr ")")
 */
import java.io.*;
import java.util.*;
/*
 * S5本体
 */
class S5
{
	public static void main(String[] args) throws IOException
	{
		boolean debug = false;
		System.out.println("S5 cpmpiler written by Qzlzdy");
		if(args.length == 2)
		{
			if(args[0].equalsIgnoreCase("-debug_token_manger"))
				debug = true;
			else
			{
				System.out.println("Wrong number cmd line args");
				System.exit(1);
			}
		}
		else if( args.length != 1)
		{
			System.out.println("Wrong number cmd line args");
			System.exit(1);
		}
		String inFileName = args[args.length - 1] + ".txt";
		String outFileName = args[args.length - 1] + "out.txt";
		Scanner inFile = new Scanner(new File(inFileName));
		PrintWriter outFile = new PrintWriter(outFileName);
		outFile.println("; from S5 compiler written by Qzlzdy");
		S5SymTab st = new S5SymTab();
		S5TokenMgr tm = new S5TokenMgr(inFile,outFile,debug);
		S5CodeGen cg = new S5CodeGen(outFile,st);
		S5Parser parser = new S5Parser(st,tm,cg);
		try
		{
			parser.parse();
		}
		catch(RuntimeException e)
		{
			System.err.println(e.getMessage());
			outFile.println(e.getMessage());
			outFile.close();
			System.exit(1);
		}
		outFile.close();
	}
}
/*
 * Token类
 */
class Token
{
	public int kind;
	public int beginLine,beginColumn,endLine,endColumn;
	public String image;
	public Token next;
}
/*
 * S5常量
 */
interface S5Constants
{
	// S5单词符号常量
	int EOF = 0;
	int UNSIGNED = 1;
	int ID = 2;
	int STRING = 3;
	int EQUAL = 4;
	int SEMICOLON = 5;
	int LEFTPAREN = 6;
	int RIGHTPAREN = 7;
	int LEFTBRACE = 8;
	int RIGHTBRACE = 9;
	int ADD = 10;
	int SUB = 11;
	int MUL = 12;
	int DIV = 13;
	int PRINTLN = 14;
	int PRINT = 15;
	int READINT = 16;
	int WHILE = 17;
	int IF = 18;
	int ELSE = 19;
	int DO = 20;
	int EXTERN = 21;
	int INT = 22;
	int VOID = 23;
	int COMMA = 24;
	int ERROR = 25;
	String[] tokenImage = 
	{
		"<EOF>",
		"<UNSIGNED>",
		"<ID>",
		"<STRING>",
		"\"=\"",
		"\";\"",
		"\"(\"",
		"\")\"",
		"\"{\"",
		"\"}\"",
		"\"+\"",
		"\"-\"",
		"\"*\"",
		"\"/\"",
		"\"println\"",
		"\"print\"",
		"\"readint\"",
		"\"while\"",
		"\"if\"",
		"\"else\"",
		"\"do\"",
		"\"extern\"",
		"\"int\"",
		"\"void\"",
		"\",\"",
		"<ERROR>"
	};
	// S5变量类型常量
	int LOCAL = 0;
	int GLOBALV = 1;
	int EXTERNV = 2;
	int FUNCADEFI = 3;
	int FUNCACALL = 4;
	String[] variableKind =
	{
		"local",
		"global",
		"extern",
		"funcationdefinition",
		"funcationcall"
	};
} 
/*
 * S5符号表
 */
class S5SymTab implements S5Constants
{
	private ArrayList<String> symbol;
	private ArrayList<Integer> relAdd;
	private ArrayList<Integer> category;
	public S5SymTab()
	{
		symbol = new ArrayList<String>();
		relAdd = new ArrayList<Integer>();
		category = new ArrayList<Integer>();
	}
	public void enter(String sym,int ra,int cat)
	{
		int index = find(sym);
		if(index < 0)
		{
			symbol.add(sym);
			relAdd.add(ra);
			category.add(cat);
			return;
		}
		if(cat == FUNCACALL && getCategory(index) == FUNCACALL)
			;
		else if(cat == FUNCACALL && getCategory(index) == FUNCADEFI)
			;
		else if(cat == FUNCADEFI && getCategory(index) == FUNCACALL)
			category.set(index,FUNCADEFI);
		else if(cat == LOCAL && getCategory(index) == GLOBALV)
		{
			symbol.add(sym);
			relAdd.add(ra);
			category.add(cat);
		}
		else if(cat == LOCAL && getCategory(index) == EXTERNV)
		{
			symbol.add(sym);
			relAdd.add(ra);
			category.add(cat);
		}
		else
			throw new RuntimeException("Illegal variable or funcation");
	}
	public int find(String sym)
	{
		return symbol.lastIndexOf(sym);
	}
	public String getSymbol(int index)
	{
		return symbol.get(index);
	}
	public Integer getRelAdd(int index)
	{
		return relAdd.get(index);
	}
	public Integer getCategory(int index)
	{
		return category.get(index);
	}
	public int getSize()
	{
		return symbol.size();
	}
	public void localRemove()
	{
		int index = category.lastIndexOf(LOCAL);
		while(index >= 0)
		{
			symbol.remove(index);
			relAdd.remove(index);
			category.remove(index);
			index = category.lastIndexOf(LOCAL);
		}
	}
}
/*
 * S5代码生成器
 */
class S5CodeGen implements S5Constants
{
	private PrintWriter outFile;
	private S5SymTab st;
	private int labelNumber;
	public S5CodeGen(PrintWriter outFile,S5SymTab st)
	{
		this.outFile = outFile;
		this.st = st;
		labelNumber = 0;
	}
	public void emitString(String s)
	{
		outFile.println(s);
	}
	public void emitInstruction(String op)
	{
		outFile.printf("	%s%n",op);
	}
	public void emitInstruction(String op,String opnd)
	{
		outFile.printf("	%-4s	%s%n",op,opnd);
	}
	public void emitdw(String label,String value)
	{
		outFile.printf("%-9s dw	%s%n",label,value);
	}
	public void endCode()
	{
		outFile.println();
		int size = st.getSize();
		for(int i = 0; i < size; i++)
		{
			if(st.getCategory(i) == FUNCACALL)
				emitdw("extern",st.getSymbol(i));
		}
	}
	public String getLabel()
	{
		return "@L" + labelNumber++;
	}
	public void emitLabel(String label)
	{
		outFile.println(label + ":");
	}
	public void push(int p)
	{
		if(st.getCategory(p) == LOCAL)
			outFile.printf("	pr	%-4d	;local%n",st.getRelAdd(p));
		else
			outFile.printf("	p	%-4s	;%s%n",
				st.getSymbol(p),variableKind[st.getCategory(p)]);
	}
	public void pushAddress(int p)
	{
		if(st.getCategory(p) == LOCAL)
			outFile.printf("	cora	%-4d	;local%n",st.getRelAdd(p));
		else
			outFile.printf("	pc	%-4s	;%s%n",
				st.getSymbol(p),variableKind[st.getCategory(p)]);	
	}
}
/*
 * S5单词符号管理器
 */
class S5TokenMgr implements S5Constants
{
	private Scanner inFile;
	private PrintWriter outFile;
	private boolean debug;
	private char currentChar;
	private int currentLineNumber;
	private int currentColumnNumber;
	private String inputLine;
	private Token token;
	private StringBuffer buffer;
	public S5TokenMgr(Scanner inFile,PrintWriter outFile,boolean debug)
	{
		this.inFile = inFile;
		this.outFile = outFile;
		this.debug = debug;
		currentChar = '\n';
		currentLineNumber = 0;
		buffer = new StringBuffer();
	}
	private void getNextChar()
	{
		if(currentChar == EOF)
			return;
		if(currentChar == '\n')
		{
			if(inFile.hasNextLine())
			{
				inputLine = inFile.nextLine();
				outFile.println(";" + inputLine);
				inputLine = inputLine + "\n";
				currentColumnNumber = 0;
				currentLineNumber++;
			}
			else
			{
				currentChar = EOF;
				return;
			}
		}
		currentChar = inputLine.charAt(currentColumnNumber++);
		if(currentChar == '/' && inputLine.charAt(currentColumnNumber) == '/')
			currentChar = '\n';
	}
	public Token getNextToken()
	{
		while(Character.isWhitespace(currentChar))
			getNextChar();
		token = new Token();
		token.next = null;
		token.beginLine = currentLineNumber;
		token.beginColumn = currentColumnNumber;
		if(currentChar == EOF)
		{
			token.image = "<EOF>";
			token.kind = EOF;
			token.endLine = currentLineNumber;
			token.endColumn = currentColumnNumber;
		}
		else if(Character.isDigit(currentChar))
		{
			buffer.setLength(0);
			do
			{
				buffer.append(currentChar);
				token.endLine = currentLineNumber;
				token.endColumn = currentColumnNumber;
				getNextChar();
			}while(Character.isDigit(currentChar));
			token.image = buffer.toString();
			token.kind = UNSIGNED;
		}
		else if(Character.isLetter(currentChar))
		{
			buffer.setLength(0);
			do
			{
				buffer.append(currentChar);
				token.endLine = currentLineNumber;
				token.endColumn = currentColumnNumber;
				getNextChar();
			}while(Character.isLetterOrDigit(currentChar));
			token.image = buffer.toString();
			if(token.image.equals("println"))
				token.kind = PRINTLN;
			else if(token.image.equals("print"))
				token.kind = PRINT;
			else if(token.image.equals("readint"))
				token.kind = READINT;
			else if(token.image.equals("while"))
				token.kind = WHILE;
			else if(token.image.equals("if"))
				token.kind = IF;
			else if(token.image.equals("else"))
				token.kind = ELSE;
			else if(token.image.equals("do"))
				token.kind = DO;
			else if(token.image.equals("extern"))
				token.kind = EXTERN;
			else if(token.image.equals("int"))
				token.kind = INT;
			else if(token.image.equals("void"))
				token.kind = VOID;
			else
				token.kind = ID;
		}
		else if(currentChar == '\"')
		{
			buffer.setLength(0);
			do
			{
				buffer.append(currentChar);
				token.endLine = currentLineNumber;
				token.endColumn = currentColumnNumber;
				getNextChar();
			}while(currentChar != '\n' && currentChar != '\r' && currentChar != '\"');
			if(currentChar == '\"')
			{
				buffer.append(currentChar);
				token.endLine = currentLineNumber;
				token.endColumn = currentColumnNumber;
				getNextChar();
				token.image = buffer.toString();
				token.kind = STRING;
			}
			else
				token.kind = ERROR;
		}
		else
		{
			switch(currentChar)
			{
				case '=':
					token.kind = EQUAL;
					break;
				case ';':
					token.kind = SEMICOLON;
					break;
				case '(':
					token.kind = LEFTPAREN;
					break;
				case ')':
					token.kind = RIGHTPAREN;
					break;
				case '{':
					token.kind = LEFTBRACE;
					break;
				case '}':
					token.kind = RIGHTBRACE;
					break;
				case '+':
					token.kind = ADD;
					break;
				case '-':
					token.kind = SUB;
					break;
				case '*':
					token.kind = MUL;
					break;
				case '/':
					token.kind = DIV;
					break;
				case ',':
					token.kind = COMMA;
					break;
				default:
					token.kind = ERROR;
					break;
			}
			token.image = Character.toString(currentChar);
			token.endLine = currentLineNumber;
			token.endColumn = currentColumnNumber;
			getNextChar();
		}
		if(debug)
			outFile.printf(
				"; kd=%3d bL=%3d bC=%3d eL=%3d eC=%3d im=%s%n",
				token.kind,token.beginLine,token.beginColumn,
				token.endLine,token.endColumn,token.image);
		return token;
	}
}
/*
 * S5语法分析器
 */
class S5Parser implements S5Constants
{
	private S5SymTab st;
	private S5TokenMgr tm;
	private S5CodeGen cg;
	private Token currentToken;
	private Token previousToken;
	public S5Parser(S5SymTab st,S5TokenMgr tm,S5CodeGen cg)
	{
		this.st = st;
		this.tm = tm;
		this.cg = cg;
		currentToken = tm.getNextToken();
		previousToken = null;
	}
	private RuntimeException genEx(String errorMessage)
	{
		return new RuntimeException("Encountered \"" +
			currentToken.image + "\"on line " +
			currentToken.beginLine + ", column" +
			currentToken.beginColumn + "." +
			System.getProperty("line.separator") +
			errorMessage);
	}
	private void advance()
	{
		previousToken = currentToken;
		if(currentToken.next != null)
			currentToken = currentToken.next;
		else
			currentToken = currentToken.next = tm.getNextToken();
	}
	private Token getToken(int i)
	{
		if(i <= 0)
			return previousToken;
		Token t = currentToken;
		for(int j = 1; j < i; j++)
		{
			if(t.next != null)
				t = t.next;
			else
				t = t.next = tm.getNextToken();
		}
		return t;
	}
	private void consume(int expected)
	{
		if(currentToken.kind == expected)
			advance();
		else
			throw genEx("Expecting " + tokenImage[expected]);
	}
	public void parse()
	{
		program();
	}
	private void program()
	{
		programUnitList();
		cg.endCode();
		if(currentToken.kind != EOF)
			throw genEx("Expecting <EOF>");
	}
	private void programUnitList()
	{
		if(currentToken.kind == EOF)
			return;
		programUnit();
		programUnitList();
	}
	private void programUnit()
	{
		switch(currentToken.kind)
		{
			case EXTERN:
				externDeclaration();
				break;
			case INT:
				globalDeclaration();
				break;
			case VOID:
				funcationDefinition();
				break;
			default:
				throw genEx("Expecting declaration or definition");
		}
	}
	private void externDeclaration()
	{
		Token t;
		consume(EXTERN);
		consume(INT);
		t = currentToken;
		consume(ID);
		st.enter(t.image,0,EXTERNV);
		cg.emitInstruction("extern",t.image);
		while(currentToken.kind == COMMA)
		{
			consume(COMMA);
			t = currentToken;
			consume(ID);
			st.enter(t.image,0,EXTERNV);
			cg.emitInstruction("extern",t.image);
		}
		consume(SEMICOLON);
	}
	private void globalDeclaration()
	{
		consume(INT);
		global();
		while(currentToken.kind == COMMA)
		{
			consume(COMMA);
			global();
		}
		consume(SEMICOLON);
	}
	private void global()
	{
		Token t1,t2;
		String initVal;
		t1 = currentToken;
		consume(ID);
		cg.emitInstruction("public",t1.image);
		initVal = "0";
		if(currentToken.kind == EQUAL)
		{
			consume(EQUAL);
			initVal = "";
			if(currentToken.kind == ADD)
				consume(ADD);
			else if(currentToken.kind == SUB)
			{
				consume(SUB);
				initVal = "-";
			}
			t2 = currentToken;
			consume(UNSIGNED);
			initVal += t2.image;
		}
		st.enter(t1.image,0,GLOBALV);
		cg.emitdw(t1.image,initVal);
	}
	private void funcationDefinition()
	{
		Token t;
		consume(VOID);
		t = currentToken;
		consume(ID);
		cg.emitString("; =============== start of funcation " + t.image);
		st.enter(t.image,0,FUNCADEFI);
		cg.emitInstruction("public",t.image);
		cg.emitLabel(t.image);
		consume(LEFTPAREN);
		if(currentToken.kind == INT)
			parameterList();
		consume(RIGHTPAREN);
		consume(LEFTBRACE);
		cg.emitInstruction("esba");
		localDeclarations();
		statementList();
		consume(RIGHTBRACE);
		cg.emitInstruction("reba");
		cg.emitInstruction("ret");
		cg.emitString("; =============== end of funcation " + t.image);
		st.localRemove();
	}
	private void parameterList()
	{
		Token t = parameter();
		int p = parameterR();
		st.enter(t.image,p,LOCAL);
	}
	private Token parameter()
	{
		Token t;
		consume(INT);
		t = currentToken;
		consume(ID);
		return t;
	}
	private int parameterR()
	{
		Token t;
		int p;
		switch(currentToken.kind)
		{
			case COMMA:
				consume(COMMA);
				t = parameter();
				p = parameterR();
				st.enter(t.image,p,LOCAL);
				return p + 1;
			case RIGHTBRACE:
				return 2;
			default:
				throw genEx("Expecting parameter");
		}
	}
	private void localDeclarations()
	{
		int relativeAddress = -1;
		while(currentToken.kind == INT)
		{
			consume(INT);
			local(relativeAddress--);
			while(currentToken.kind == COMMA)
			{
				consume(COMMA);
				local(relativeAddress--);
			}
			consume(SEMICOLON);
		}
	}
	private void local(int relativeAddress)
	{
		String sign;
		Token t = currentToken;
		consume(ID);
		st.enter(t.image,relativeAddress,LOCAL);
		switch(currentToken.kind)
		{
			case EQUAL:
				consume(EQUAL);
				sign = "=";
				if(currentToken.kind == ADD)
					consume(ADD);
				else if(currentToken.kind == SUB)
				{
					consume(SUB);
					sign = "-";
				}
				t = currentToken;
				consume(UNSIGNED);
				cg.emitInstruction("pwc",sign + t.image);
				break;
			case COMMA:
			case SEMICOLON:
				cg.emitInstruction("asp","-1");
				break;
			default:
				throw genEx("Expecting \"=\" \",\" or \",\"");
		}
	}
	private void statementList()
	{
		if(currentToken.kind == RIGHTBRACE)
			return;
		statement();
		statementList();
	}
	private void statement()
	{
		switch(currentToken.kind)
		{
			case ID:
				if(getToken(2).kind == EQUAL)
					assignmentStatement();
				else
					funcationCall();
				break;
			case PRINTLN:
				printlnStatement();
				break;
			case PRINT:
				printStatement();
				break;
			case SEMICOLON:
				nullStatement();
				break;
			case LEFTBRACE:
				compoundStatement();
				break;
			case READINT:
				readintStatement();
				break;
			case WHILE:
				whileStatement();
				break;
			case IF:
				ifStatement();
				break;
			case DO:
				doWhileStatement();
				break;
			default:
				throw genEx("Expecting statement");
		}
	}
	private void assignmentStatement()
	{
		int index;
		Token t = currentToken;
		consume(ID);
		index = st.find(t.image);
		cg.pushAddress(index);
		consume(EQUAL);
		assignmentTail();
		cg.emitInstruction("stav");
	}
	private void assignmentTail()
	{
		Token t;
		int index;
		if(getToken(1).kind == ID && getToken(2).kind == EQUAL)
		{
			t = currentToken;
			consume(ID);
			index = st.find(t.image);
			cg.pushAddress(index);
			consume(EQUAL);
			assignmentTail();
			cg.emitInstruction("dupe");
			cg.emitInstruction("rot");
			cg.emitInstruction("stav");
		}
		else
		{
			expr();
			consume(SEMICOLON);
		}
	}
	private void printlnStatement()
	{
		consume(PRINTLN);
		consume(LEFTPAREN);
		switch(currentToken.kind)
		{
			case STRING:
			case ID:
			case UNSIGNED:
			case ADD:
			case SUB:
			case LEFTPAREN:
				printArg();
				break;
			case RIGHTPAREN:
				;
				break;
			default:
				throw genEx("Expecting printArg or null");
		}
		cg.emitInstruction("pc","'\\n'");
		cg.emitInstruction("aout");
		consume(RIGHTPAREN);
		consume(SEMICOLON);
	}
	private void printStatement()
	{
		consume(PRINT);
		consume(LEFTPAREN);
		printArg();
		consume(RIGHTPAREN);
		consume(SEMICOLON);
	}
	private void printArg()
	{
		Token t;
		String label;
		switch(currentToken.kind)
		{
			case STRING:
				t = currentToken;
				consume(STRING);
				label = cg.getLabel();
				cg.emitInstruction("pc",label);
				cg.emitInstruction("sout");
				cg.emitdw("^" + label + ":",t.image);
				break;
			case ID:
			case UNSIGNED:
			case ADD:
			case SUB:
			case LEFTPAREN:
				expr();
				cg.emitInstruction("dout");
				break;
			default:
				throw genEx("Expecting string or expr");
		}
	}
	private void nullStatement()
	{
		consume(SEMICOLON);
	}
	private void compoundStatement()
	{
		consume(LEFTBRACE);
		compoundList();
		consume(RIGHTBRACE);
	}
	private void compoundList()
	{
		if(currentToken.kind == RIGHTBRACE)
			return;
		statement();
		compoundList();
	}
	private void readintStatement()
	{
		Token t;
		int index;
		consume(READINT);
		consume(LEFTPAREN);
		t = currentToken;
		consume(ID);
		index = st.find(t.image);
		cg.pushAddress(index);
		cg.emitInstruction("din");
		cg.emitInstruction("stav");
		consume(RIGHTPAREN);
		consume(SEMICOLON);
	}
	private void whileStatement()
	{
		String label1;
		String label2;
		consume(WHILE);
		label1 = cg.getLabel();
		cg.emitLabel(label1);
		consume(LEFTPAREN);
		expr();
		consume(RIGHTPAREN);
		label2 = cg.getLabel();
		cg.emitInstruction("jz",label2);
		statement();
		cg.emitInstruction("ja",label1);
		cg.emitLabel(label2);
	}
	private void ifStatement()
	{
		String label1;
		consume(IF);
		consume(LEFTPAREN);
		expr();
		consume(RIGHTPAREN);
		label1 = cg.getLabel();
		cg.emitInstruction("jz",label1);
		statement();
		elsePart(label1);
	}
	private void elsePart(String label1)
	{
		if(currentToken.kind != ELSE)
		{
			cg.emitLabel(label1);
			return;
		}
		String label2;
		consume(ELSE);
		label2 = cg.getLabel();
		cg.emitInstruction("ja",label2);
		cg.emitLabel(label1);
		statement();
		cg.emitLabel(label2);
	}
	private void doWhileStatement()
	{
		String label;
		consume(DO);
		label = cg.getLabel();
		cg.emitLabel(label);
		compoundStatement();
		consume(WHILE);
		consume(LEFTPAREN);
		expr();
		consume(RIGHTPAREN);
		cg.emitInstruction("jnz",label);
	}
	private void funcationCall()
	{
		int count;
		Token t = currentToken;
		consume(ID);
		st.enter(t.image,0,FUNCACALL);
		consume(LEFTPAREN);
		count = 0;
		if(currentToken.kind != RIGHTPAREN)
			count = argumentList();
		cg.emitInstruction("call",t.image);
		if(count > 0)
			cg.emitInstruction("asp",count + "");
		consume(RIGHTPAREN);
		consume(SEMICOLON);
	}
	private int argumentList()
	{
		int count;
		expr();
		count = 1;
		while(currentToken.kind == COMMA)
		{
			consume(COMMA);
			expr();
			count++;
		}
		return count;
	}
	private void expr()
	{
		term();
		termList();
	}
	private void termList()
	{
		switch(currentToken.kind)
		{
			case ADD:
				consume(ADD);
				term();
				cg.emitInstruction("add");
				termList();
				break;
			case SUB:
				consume(SUB);
				term();
				cg.emitInstruction("sub");
				termList();
				break;
			case RIGHTPAREN:
			case SEMICOLON:
				;
				break;
			default:
				throw genEx("Expecting \"+\",\"-\",\")\", or \";\"");
		}
	}
	private void term()
	{
		factor();
		factorList();
	}
	private void factorList()
	{
		switch(currentToken.kind)
		{
			case MUL:
				consume(MUL);
				factor();
				cg.emitInstruction("mul");
				factorList();
				break;
			case DIV:
				consume(DIV);
				factor();
				cg.emitInstruction("div");
				factorList();
				break;
			case ADD:
			case SUB:
			case RIGHTPAREN:
			case SEMICOLON:
				;
				break;
			default:
				throw genEx("Expecting op,\")\", or \";\"");
		}
	}
	private void factor()
	{
		Token t;
		int index;
		switch(currentToken.kind)
		{
			case UNSIGNED:
				t = currentToken;
				consume(UNSIGNED);
				if(t.image.length() > 5 || Integer.parseInt(t.image) > 32767)
					throw genEx("Expecting integer (-32768 to 32767)");
				cg.emitInstruction("pwc",t.image);
				break;
			case ID:
				t = currentToken;
				consume(ID);
				index = st.find(t.image);
				cg.push(index);
				break;
			case ADD:
				consume(ADD);
				factor();
				break;
			case SUB:
				consume(SUB);
				switch(currentToken.kind)
				{
					case UNSIGNED:
						t = currentToken;
						consume(UNSIGNED);
						if(t.image.length() > 5 || 
							Integer.parseInt(t.image) > 32768)
							throw genEx("Expecting integer (-32768 to 32767)");
						cg.emitInstruction("pwc","-" + t.image);
						break;
					case ID:
						t = currentToken;
						consume(ID);
						index = st.find(t.image);
						cg.push(index);
						cg.emitInstruction("neg");
						break;
					case LEFTPAREN:
						consume(LEFTPAREN);
						expr();
						consume(RIGHTPAREN);
						cg.emitInstruction("neg");
						break;
					case ADD:
						consume(ADD);
						factor();
						cg.emitInstruction("neg");
						break;
					case SUB:
						consume(SUB);
						factor();
						break;
					default:
						throw genEx("Expecting factor");
				}
				break;
			case LEFTPAREN:
				consume(LEFTPAREN);
				expr();
				consume(RIGHTPAREN);
				break;
			default:
				throw genEx("Expecting factor");
		}
	}
}