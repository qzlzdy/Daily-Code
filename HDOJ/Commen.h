//高精度加法
class BigNum
{
public:
    BigNum(int num);
    BigNum(string num);
    int length();
    BigNum operator+(BigNum &num);
    char &operator[](int n);
    friend ostream &operator<<(ostream &out,const BigNum &num);
private:
    string _num;
};
BigNum::BigNum(int num)
{
    _num = to_string(num);
}
BigNum::BigNum(string num)
{
    _num = num;
}
int BigNum::length()
{
    return _num.length();
}
BigNum BigNum::operator +(BigNum &num)
{
    string sum;
    int i = length() - 1,j = num.length() - 1;
    int carry = 0,digit;
    while(i >= 0 && j >= 0)
    {
        digit = _num[i--] + num[j--] - 2 * '0' + carry;
        carry = digit / 10;
        digit %= 10;
        sum.insert(sum.begin(),'0' + digit);
    }
    while(i >= 0)
    {
        digit = _num[i--] - '0' + carry;
        carry = digit / 10;
        digit %= 10;
        sum.insert(sum.begin(),'0' + digit);
    }
    while(j >= 0)
    {
        digit = num[j--] - '0' + carry;
        carry = digit / 10;
        digit %= 10;
        sum.insert(sum.begin(),'0' + digit);
    }
    if(carry != 0)
        sum.insert(sum.begin(),'0' + carry);
    return BigNum(sum);
}
char &BigNum::operator [](int n)
{
    return _num[n];
}
ostream &operator<<(ostream &out,const BigNum &num)
{
    out<<num._num;
    return out;
}

//高精度乘法
class Bignum{
public:
    Bignum(int num);
    Bignum operator*(const Bignum& N);
    friend ostream& operator<<(ostream& out,const Bignum& N);
    int& operator[](int i);
    const int& operator[](int i)const;
    int size()const;
private:
    void pop_back();
    void resize(int count);
    vector<int> _num;
};
Bignum::Bignum(int num){
    while(num != 0){
        _num.push_back(num % 10);
        num /= 10;
    }
}
Bignum Bignum::operator *(const Bignum& N){
    Bignum R(0);
    R.resize(size() + N.size());
    for(int i = 0; i < size(); i++)
        for(int j = 0; j < N.size(); j++)
            R[i + j] += _num[i] * N[j];
    int digit,carry = 0;
    for(int i = 0; i < R.size(); i++){
        digit = R[i] + carry;
        R[i] = digit % 10;
        carry = digit / 10;
    }
    while(R[R.size() - 1] == 0)
        R.pop_back();
    return R;
}
ostream& operator<<(ostream& out,const Bignum& N){
    for(int i = N.size() - 1; i >= 0; i--)
        out<<N[i];
    return out;
}
int& Bignum::operator [](int i){
    return _num[i];
}
const int& Bignum::operator [](int i)const{
    return _num[i];
}
int Bignum::size()const{
    return _num.size();
}
void Bignum::pop_back(){
    _num.pop_back();
}
void Bignum::resize(int count){
    _num.resize(count,0);
}
Bignum bignumFact(Bignum& N,int n){
    Bignum R(1);
    for(int i = 2; i <= n; i++)
        R = R * Bignum(i);
    return R;
}

//投票问题
int main(){
    int N,max;
    string str,maxStr;
    map<string,int> m; 
    while(cin>>N,N != 0){
        m.clear();
        max = 0;
        maxStr = "";
        while(N > 0){
            cin>>str;
            if(m.find(str) == m.end())
                m[str] = 1;
            else
                m[str]++;
            if(m[str] > max){
                max = m[str];
                maxStr = str;
            }
            N--;
        }
        cout<<maxStr<<endl;
    }
} 

//数论-模
int main(){
    int A,B,n;
    while(cin>>A>>B>>n){
        if(A == 0 && B == 0 && n == 0)
            break;
        vector<int> arr(2,1);
        int prev = (A + B) % 7;
        int curr = (A * prev + B) % 7;
        bool loop = false;
        int i;
        while(!loop){
            for(i = 0; i < arr.size() - 1; i++){
                if(arr[i] == prev && arr[i + 1] == curr){
                    loop = true;
                    break;
                }
            }
            if(!loop){
                arr.push_back(prev);
                prev = curr;
                curr = (A * prev + B * arr[arr.size() - 1]) % 7;
            }
        }
        int a = i + (n - i - 1) % (arr.size() - i);
        cout<<arr[n <= i ? n - 1 : a]<<endl;
    }
}

//递推求解
long long func(vector<long long>& memo,unsigned int i){
    if(i <= memo.size())
        return memo[i - 1];
    memo.push_back(func(memo,i - 2) + func(memo,i - 1));
    return memo[i - 1];
}
int main(){
    int N,a,b;
    vector<long long> memo{1,2};
    cin>>N;
    while(N--){
        cin>>a>>b;
        cout<<func(memo,b - a)<<endl;
    }
}

//可图性
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,d;
        cin>>n;
        vector<int> dgr;
        while(n--){
            cin>>d;
            dgr.push_back(d);
        }
        sort(dgr.rbegin(),dgr.rend());
        d = dgr[0];
        bool flag = true;
        while(d != 0 && flag){
            dgr[0] = 0;
            for(int i = 1; i <= d; i++){
                dgr[i]--;
                if(dgr[i] < 0){
                    flag = false;
                    break;
                }
            }
            sort(dgr.rbegin(),dgr.rend());
            d = dgr[0];
        }
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}

//经典贪心算法
class Bangumi{
public:
    int begin;
    int end;
    Bangumi(){};
    Bangumi(int beg,int en);
    bool operator()(const Bangumi& a,const Bangumi &b)const;
};
Bangumi::Bangumi(int beg,int en){
    begin = beg;
    end = en;
}
bool Bangumi::operator()(const Bangumi& a,const Bangumi& b)const{
    return a.end < b.end;
}
int main(){
    int n;
    while(cin>>n,n != 0){
        vector<Bangumi> bgm;
        int beg,en;
        for(int i = 0; i < n; i++){
            cin>>beg>>en;
            bgm.push_back(Bangumi(beg,en));
        }
        sort(bgm.begin(),bgm.end(),Bangumi());
        int last = 0;
        int sum = 0;
        vector<Bangumi>::iterator it = bgm.begin();
        while(it != bgm.end()){
            if((*it).begin >= last){
                sum++;
                last = (*it).end;
            }
            it++;
        }
        cout<<sum<<endl;
    }
    return 0;
} 

//动态规划-数塔
class Axis{
public:
    Axis(int n);
    int getCooks();
private:
    void resize(int count);
    vector<vector<int> > _cooks;
};
Axis::Axis(int n){
    int x,T;
    for(int i = 0; i < n; i++){
        scanf("%d%d",&x,&T);
        if(_cooks.size() < T)
            resize(T);
        _cooks[T - 1][x]++;
    }
}
int Axis::getCooks(){
    for(int i = _cooks.size() - 2; i >= 0; i--){
        for(int j = 0; j < 11; j++){
            int maxi = _cooks[i + 1][j];
            if(j > 0)
                maxi = max(maxi,_cooks[i + 1][j - 1]);
            if(j < 10)
                maxi = max(maxi,_cooks[i + 1][j + 1]);
            _cooks[i][j] += maxi;
        }
    }
    return max(_cooks[0][4],max(_cooks[0][5],_cooks[0][6]));
}
void Axis::resize(int count){
    _cooks.resize(count,vector<int>(11,0));
}
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        Axis axis(n);
        cout<<axis.getCooks()<<endl;
    }
}

//并查集 
class Set{
public:
    Set();
    Set *findSet();
    void unionSet(Set *x);
private:
    void link(Set *x);
    Set *par;
    int rank;
};
Set::Set(){
    par = this;
    rank = 0;
}
Set *Set::findSet(){
    if(par != this)
        par = par->findSet();
    return par;
}
void Set::unionSet(Set *x){
    findSet();
    link(x->findSet());
}
void Set::link(Set *x){
    if(par->rank > x->rank)
        x->par = par;
    else{
        par->par = x;
        if(x->rank == par->rank)
            x->rank++;
    }
}
//BFS 
vector<vector<int> >const dect = {{1,0},{0,1},{-1,0},{0,-1}};
int const SIZE = 4;
int const X = 0;
int const Y = 1;
vector<vector<bool> > visited;
int H,W;
bool passable(int x,int y){
    return 0 <= x && x < H && 0 <= y && y < W && !visited[x][y];
}
class Point{
public:
    Point(int pos_x,int pos_y);
    int x,y;
};
Point::Point(int pos_x,int pos_y){
    x = pos_x;
    y = pos_y;
}
int main(){
    while(cin>>W>>H){
        if(H == 0 && W == 0)
            break;
        visited.clear();
        Point start(0,0);
        char t;
        for(int i = 0; i < H; i++){
            vector<bool> row;
            for(int j = 0; j < W; j++){
                cin>>t;
                if(t == '@'){
                    row.push_back(true);
                    start = Point(i,j);
                }else
                    row.push_back(t == '.' ? false : true);
            }
            visited.push_back(row);
        }
        queue<Point> Q;
        int sum = 1;
        Q.push(start);
        while(!Q.empty()){
            Point curr = Q.front();
            Q.pop();
            //cout<<curr.x<<" "<<curr.y<<endl;
            Point next(0,0);
            for(int i = 0; i < SIZE; i++){
                next.x = curr.x + dect[i][X];
                next.y = curr.y + dect[i][Y];
                if(passable(next.x,next.y)){
                    visited[next.x][next.y] = true;
                    sum++;
                    Q.push(next);
                }
            }
        }
        cout<<sum<<endl;
    }
}

//计算几何
class Point{
public:
    Point(double pos_x = 0,double pos_y = 0);
    friend istream& operator>>(istream& in,Point& P);
    Point operator-(Point& p);
    double x,y;
};
Point::Point(double pos_x,double pos_y){
    x = pos_x;
    y = pos_y;
}
istream& operator>>(istream& in,Point& P){
    in>>P.x>>P.y;
    return in;
}
Point Point::operator -(Point& p){
    return Point(p.x - x,p.y - y);
}
class Segment{
public:
    Segment();
    Segment(Point b,Point e);
    friend istream& operator>>(istream& in,Segment& L);
    double direction(Segment& L);
    double direction(Point& P);
    bool onSegment(Point& P);
    bool isIntersect(Segment& L);
    Point begin,end;
};
Segment::Segment(){
    begin = Point();
    end = Point();
}
Segment::Segment(Point b,Point e){
    begin = b;
    end = e;
}
istream& operator>>(istream& in,Segment& L){
    in>>L.begin>>L.end;
    return in;

}
double Segment::direction(Segment& L){
    Point t1 = end - begin;
    Point t2 = L.end - L.begin;
    return t1.x * t2.y - t2.x * t1.y;
}
double Segment::direction(Point& P){
    Point t1 = end - begin;
    Point t2 = P - begin;
    return t1.x * t2.y - t2.x * t1.y;
}
bool Segment::onSegment(Point& P){
    if(min(begin.x,end.x) <= P.x && P.x <= max(begin.x,end.x) &&
            min(begin.y,end.y) <= P.y && P.y <= max(begin.y,end.y))
        return true;
    return false;
}
bool Segment::isIntersect(Segment& L){
    int d1 = L.direction(begin);
    int d2 = L.direction(end);
    int d3 = direction(L.begin);
    int d4 = direction(L.end);
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
            ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    if(d1 == 0 && L.onSegment(begin))
        return true;
    if(d2 == 0 && L.onSegment(end))
        return true;
    if(d3 == 0 && onSegment(L.begin))
        return true;
    if(d4 == 0 && onSegment(L.end))
        return true;
    return false;
}
int main(){
    int N;
    while(cin>>N){
        if(N == 0)
            break;
        vector<Segment> segments;
        int count = 0;
        for(int i = 0; i < N; i++){
            Segment L;
            cin>>L;
            for(auto &it : segments){
                if(it.isIntersect(L))
                    count++;
            }
            segments.push_back(L);
        }
        cout<<count<<endl;
    }
}

//闭包
bool cmp(Point& P,Point& Q){
    return P.drection(Q) > 0;
}
int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        else if(n == 1){
            cout<<"0.00"<<endl;
            continue;
        }else if(n == 2){
            Point P,Q;
            cin>>P>>Q;
            cout<<fixed<<setprecision(2)<<P.distance(Q)<<endl;
            continue;
        }
        vector<Point> trees;
        Point min;
        cin>>min;
        for(int i = 1; i < n; i++){
            Point P;
            cin>>P;
            if(P.y < min.y || (P.y == min.y && P.x < min.x)){
                trees.push_back(min);
                min = P;
            }else
                trees.push_back(P);
        }
        for(auto &it : trees){
            it.x -= min.x;
            it.y -= min.y;
        }
        sort(trees.begin(),trees.end(),cmp);
        vector<Point> S{Point(),trees[0],trees[1]};
        for(int i = 2; i < n - 1; i++){
            while(Segment(S[S.size() - 2],S.back()).direction(Segment(S.back(),trees[i])) < 0)
                S.pop_back();
            S.push_back(trees[i]);
        }
        S.push_back(Point());
        double sum = 0;
        for(unsigned i = 0; i < S.size() - 1; i++){
            sum += S[i].distance(S[i + 1]);
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
} 
//背包问题 
using namespace std;
int main(){
    int N,M;
    while(cin>>N>>M){
        vector<int> flws(N);
        for(auto &it : flws)
            cin>>it;
        vector<int> arr(M + 1,0);
        for(int i = 0; i < N; i++)
            for(int j = 0; j <= M; j++)
                if(j >= flws[i] && arr[j - flws[i]] + 1 > arr[j])
                    arr[j] = arr[j - flws[i]] + 1;
        cout<<arr[M]<<endl;
    }
}
