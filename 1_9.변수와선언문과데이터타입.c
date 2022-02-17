//1-------------------------------------------------
int main(void)
{
    int n = 10;     //n의 데이터 타입은 int
    double d = 3.4; //d의 데이터 타입은 double

    int x[3] = {1, 2, 3}; //x의 데이터 타입은 int[3]
    int y[3][2] = {0};    //y의 데이터 타입은 int[3][2]
    //흔히 위에 2개를 배열타입이라 부른다
}

/*
변수의 이름과 초기화 구문을 제외하면 타입만 남는다.'
"int n = 10;"에서 n과 10을 제외한 것
"int x[3] = {1, 2, 3};"에서 변수이름 x과 초기값 {1,2,3};제외한 것
*/

//2-------------------------------------------------
void foo(int a); //함수의 선언
/*
void foo(int a);
이름빼고 파라미터이름 빼면
void(int);만 남는다

void(int); //foo함수의 타입
void foo(int a) //함수의 선언
*/

int main(void)
{
    int n = 10;
    double d = 3.4;

    int x[3] = {1, 2, 3};
    int y[3][2] = {0};
}

void foo(int a)
{
}

/*
정리
변수 선언문에서 "변수의 이름과 초기화 구문을 제외"하면
변수의 "데이터 타입"을 구할 수 있다

함수 선언문에서 "함수 이름과 함수 인자의 이름을 제외"하면
"함수의 타입"을 구할 수 있다.

ex)
배열타입 : "int [2]","int [3][2]"
함수타입 : "void(int)","int(double,int)"
*/