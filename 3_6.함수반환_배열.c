// 1------------------------------------------------
int f1() //반환값이 int다
{
    int n = 10;
    return n;
}

? f2() //여기는 어떻게 될까??
{
    int x[3] = {1, 2, 3};
    return x; //배열 반환
}

int main(void)
{
    int n = 0;
    double d = 0;
    int x[3] = {1, 2, 3};
}

// 2-------------------------------------------------

/*
1. 변수 선언시 Data Type 뒤에 변수 이름이 나온다.
    int n = 0;  //Data Type : int
    double d = 0;//Data Type : double

2. ★배열을 선언 할 떄는, Data Type 사이에 배열 이름이 나온다
    int x[3] = {1, 2, 3}; //Data Type : int [3]

    만약에 C언어를 이렇게 만들었다면?
    int[3] x = {1, 2, 3}; //1번규칙을 만족하고 일관성 있을텐데
    요즘에 새로 나온 언어들은 이렇게 초기화 한다.
    하지만 C는 이게 안된다

    함수 만들때도 "int[3] f2()"하면 좋을텐데 C는 그게 안된다.

3."int f2()[3]"와 같이 적자
*/

/*
배열을 반환하는 함수의 모양을 만드는 방법
배열을 선언하는 모양을 만든다
배열이름자리에 배열 이름 대산 "함수이름()"를 넣는다.

int a;
int foo();
a자리에 함수이름이랑 괄호를 넣었다.

int x[3];
int foo()[3];
x자리에 함수이름이랑 괄호를 넣었다.

이렇게 모양을 생각하자
*/

int f2()[3] //이렇게 적는다 ->그런데 에러가 뜬다! 규칙은 다 맞는데..
{
    int x[3] = {1, 2, 3};
    return x; //배열 반환
}

int main(void)
{
    int n = 0;
    double d = 0;
    int x[3] = {1, 2, 3};
}
// array를 반환하는 함수는 만들 수 없다는 에러가 발생
//배열을 반환하는 함수는 만들 수 없다.

// 3-------------------------------------------------

void f1(int y[3]) // 4.배열은 복사가 불가능해서 이렇게 받는건 불가능
{
}

void f1(int *y) // 5.OK
{
}

int main(void)
{
    int x[3] = {1, 2, 3};
    int y[3] = x; // error
    // 1.
    //배열은 복사가 불가능하다!.
    //배열은 메모리가 커서 성능저하가 있다고 판단했다.
    int *y = x;
    // 2.
    //배열은 첫번째요소의 주소로 암시적 형변환되니깐
    //위와같이 쓸 수 있다.

    f1(x); // 3.배열전달
}

// 6.함수 인자로 배열을 받을 때는 1번째 요소의 포인터 타입으로 받는다.

// 4-------------------------------------------------

/*
1.
원래 정확한 타입은
int f2()[3]
{
    int x[3] = {1, 2, 3};
    return x; //배열 반환
}
이렇게 리턴하면 x(배열)을 복사해서 리턴하는 모양이다
*/

int *f2() // 3.이렇게 적자(첫번째 요소는 int니깐)
{
    int x[3] = {1, 2, 3};
    return x; //배열 반환
    // 2. 배열의 이름은 첫번째 요소의 주소로 암시적 형변환한다
}

int main(void)
{
    int x[3] = {1, 2, 3};
}

// 4.함수에서 배열을 반환할때는 첫번째 요소의 포인터 타입으로 반환한다.

// 5-------------------------------------------------

/*
원래 정확한 타입은
int f2()[3][2]
{
    int x[3][2] = {1, 2, 3, 4, 5, 6};
    return x;
}
이렇게 리턴하면 x를 복사해서 리턴하는 모양이다
*/

int (*f3())[2]
{
    int x[3][2] = {1, 2, 3, 4, 5, 6};
    return x;
}
/*
"2차배열의 이름"은 "1차배열을 가리키는 포인터"로 암시적 형변환된다.
int (*p)[2]
1차배열을 가리키는 포인터(*p)를 적고
*p자리에다가 함수이름이랑 괄호를 넣으라고 규칙으로 배움
int (*f3())[2]
*/

/*
만드는 방법
1차배열을 가리키는 포인터모양을 잡자
int (*p)[2]
p자리에 함수이름과 괄호를 넣자
int (*f3())[2]
*/

// 6-------------------------------------------------

/*
원래 정확한 타입은
int f3()[3][2][2]
{
    int x[3][2][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    return x;
}
이렇게 리턴하면 x를 복사해서 리턴하는 모양이다
*/

int (*f4())[2][2]
{
    int x[3][2][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    return x;
}

/*
"3차배열의 이름"은 "2차배열을 가리키는 포인터"로 암시적 형변환된다.
int (*p)[2][2]
2차배열을 가리키는 포인터(*p)를 적고
*p자리에다가 함수이름이랑 괄호를 넣으라고 규칙으로 배움
int (*f4())[2][2]
*/

/*
★★★★★
정리
N차 배열을 반환하는 함수는 N-1차 배열을 가리키는 포인터 타입으로 반환한다
N-1차 배열을 가리키는 포인터 변수의 모양을 만들고
변수이름 대신 "함수이름()"를 넣어준다.
*/

// 7-------------------------------------------------
//주의할점

int *f1()
{
    int x[2] = {0};
    return x;
}
// x는 지역변수라서 {}벗어나는 순간 배열은 파괴된다.

int main(void)
{
    int *ret = f1();
    ret[0] = 10; // bug가 나온다.
    // x배열은 파괴되고 없으니깐.
}

/*
지역변수로 만들어진 배열을 반환하면 안된다.
전역변수거나 static이면 반환이 된다.
*/

int *f1()
{
    static int x[2] = {0};
    return x;
}

int main(void)
{
    int *ret = f1();
    ret[0] = 10;
}