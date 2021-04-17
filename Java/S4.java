/**
 * Author: Qzlzdy
 * Version: S4
 * Date: 2017-3-11
 * Description: Compiler
 * Interface List:
 *	1. interface S4Constants
 * Class List:
 *	1. class S4
 *	2. class Token
 *	3. class S4SymTab
 *	4. class S4CodeGen
 *	5. class S4TokenMgr implements S4Constants
 *	6. class S4Parser implements S4Constants
 * Funcation List:
 *	1. S4::public static void main(String[] args) throws IOException
 *	2. S4SymTab::public void enter(String s)
 *	3. S4SymTab::public String getSymbol(int index)
 *	4. S4SymTab::public int getSize()
 *	5. S4CodeGen::public void emitInstruction(String op)
 *	6. S4CodeGen::public void emitInstruction(String op,String opnd)
 *	7. S4CodeGen::public void emitdw(String label,String value)
 *	8. S4CodeGen::public void endCode()
 *	9. S4CodeGen::public void emitString(String s)
 *	10. S4CodeGen::public String getLabel()
 *	11. S4CodeGen::public void emitLabel(String label)
 *	12. S4TokenMgr::public Token getNextToken()
 *	13. S4Parser::public void parse()
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
 * （3）支持错误恢复
 * 源语言文法：
 * program: statementList <EOF>
 * statementList: statement statementList | λ
 * statement: asignmentStatement | printlnStatement | printStatement
 *	| nullStatement | compoundStatement | readintStatement
 *	| whileStatement | ifStatement | dowhileStatement
 * assignmentStatement: <ID> "=" assignmentTail
 * assignmentTail: <ID> "=" assignmentTail | expr
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
 * dowhileStatement: "do" statement "while" "(" expr ")" ";"
 * expr: term termList
 * termList: "+" term termList | "-" term termList | λ
 * term: factor factorList
* factorList: "*" factor factorList | "/" factor factorList | λ
 * factor: <UNSIGNED> | <ID> | "+" factor | "-" <UNSIGNED> | "(" expr ")"
 *	| "-" (<UNSIGNED> | <ID> | "+" factor | "-" factor | "(" expr ")")
 */
import java.io.*;
import java.util.*;
/*
 * S4本体
 */
class S4
{
	public static void main(String[] args) throws IOException
	{
		boolean debug = false;
		System.out.println("S4 cpmpiler written by Qzlzdy");
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
		outFile.println("; from S4 compiler written by Qzlzdy");
		S4SymTab st = new S4SymTab();
		S4TokenMgr tm = new S4TokenMgr(inFile,outFile,debug);
		S4CodeGen cg = new S4CodeGen(outFile,st);
		S4Parser parser = new S4Parser(st,tm,cg);
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
 * S4符号常量
 */
interface S4Constants
{
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
	int ERROR = 21;
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
		"<ERROR>"
	};
} 
/*
 * S4符号表
 */
class S4SymTab
{
	private ArrayList<String> symbol;
	public S4SymTab()
	{
		symbol = new ArrayList<String>();
	}
	public void enter(String s)
	{
		int index = symbol.indexOf(s);
		if(index < 0)
			symbol.add(s);
	}
	public String getSymbol(int index)
	{
		return symbol.get(index);
	}
	public int getSize()
	{
		return symbol.size();
	}
}
/*
 * S4代码生成器
 */
class S4CodeGen
{
	private PrintWriter outFile;
	private S4SymTab st;
	private int labelNumber;
	public S4CodeGen(PrintWriter outFile,S4SymTab st)
	{
		this.outFile = outFile;
		this.st = st;
		labelNumber = 0;
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
		emitInstruction("halt");
		int size = st.getSize();
		for(int i = 1; i < size; i++)
			emitdw(st.getSymbol(i),"0");
	}
	public String getLabel()
	{
		return "@L" + labelNumber++;
	}
	public void emitString(String s)
	{
		outFile.printf("%s%n",s);
	}
	public void emitLabel(String label)
	{
		outFile.printf("%s",label + ":");
	}
}
/*
 * S4单词符号管理器
 */
class S4TokenMgr implements S4Constants
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
	public S4TokenMgr(Scanner inFile,PrintWriter outFile,boolean debug)
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
 * S4语法分析器
 */
class S4Parser implements S4Constants
{
	private S4SymTab st;
	private S4TokenMgr tm;
	private S4CodeGen cg;
	private Token currentToken;
	private Token previousToken;
	public S4Parser(S4SymTab st,S4TokenMgr tm,S4CodeGen cg)
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
		statementList();
		cg.endCode();
		if(currentToken.kind != EOF)
			throw genEx("Expecting <EOF>");
	}
	private void statementList()
	{
		if(currentToken.kind == EOF)
			return;
		statement();
		statementList();
	}
	private void statement()
	{
		try{
			switch(currentToken.kind)
			{
				case ID:
					assignmentStatement();
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
					dowhileStatement();
					break;
				default:
					throw genEx("Expecting statement");
			}
		}
		catch(RuntimeException e)
		{
			System.err.println(e.getMessage());
			cg.emitString(e.getMessage());
			while(currentToken.kind != SEMICOLON && currentToken.kind != EOF)
				advance();
			if(currentToken.kind != EOF)
				advance();
		}
	}
	private void assignmentStatement()
	{
		Token t;
		t = currentToken;
		consume(ID);
		st.enter(t.image);
		cg.emitInstruction("pc",t.image);
		consume(EQUAL);
		assignmentTail();
		cg.emitInstruction("stav");
	}
	private void assignmentTail()
	{
		Token t;
		if(getToken(1).kind == ID && getToken(2).kind == EQUAL)
		{
			t = currentToken;
			consume(ID);
			st.enter(t.image);
			cg.emitInstruction("pc",t.image);
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
		consume(READINT);
		consume(LEFTPAREN);
		t = currentToken;
		consume(ID);
		st.enter(t.image);
		cg.emitInstruction("pc",t.image);
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
	private void dowhileStatement()
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
		switch(currentToken.kind)
		{
			case UNSIGNED:
				t = currentToken;
				consume(UNSIGNED);
				if(t.image.length() > 5 || Integer.parserInt(t.image) > 32767)
					throw genEx("Expecting integer (-32768 to 32767)");
				cg.emitInstruction("pwc",t.image);
				break;
			case ID:
				t = currentToken;
				consume(ID);
				st.enter(t.image);
				cg.emitInstruction("p",t.image);
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
							Integer.parserInt(t.image) > 32768)
							throw genEx("Expecting integer (-32768 to 32767)");
						cg.emitInstruction("pwc","-" + t.image);
						break;
					case ID:
						t = currentToken;
						consume(ID);
						st.enter(t.image);
						cg.emitInstruction("p",t.image);
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