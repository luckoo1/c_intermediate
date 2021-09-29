int main(void)
{
    // void a; //error

    int n = 0x11223344;

    int *p1 = &n;
    char *p2 = (char *)&n;
    /*
    &n메모리를 바라보는 관점을 바꾸는거라고 배웠다
    앞으로 이건 1바이트로 볼거다!
    메모리에 있는 데이터의 정보 변경
    */

    void *p3 = &n; //ok
    /*
    데이터 정보가 필요없고 주소정보만 꺼낼거다!
    무조건 주소만 있으면 된다
    */

    //주소출력은 문제없다
    printf("%p\n", p1); //OK
    printf("%p\n", p2); //OK
    printf("%p\n", p3); //OK

    printf("%x\n", *p1); //0x11223344
    printf("%x\n", *p2); //0x44
    printf("%x\n", *p3); //error
    //그 메모리에 뭐가있는지 모른다
    //주소는 담을 수 있지만 역참조하면 데이터정보를 알 수 없다.
}

/*
void 타입
함수의 반환값이나 인자가 없음을 나타낼 때 사용
void타입의 변수는 만들 수 없다
void 타입의 포인터는 만들수 있다
*/

/*
void*의 의미
메모리 주소만 보관하고 타입에 대한 정보가 없는 포인터

int *p1
메모리에 있는 데이터 정보 : 4바이트 크기의 정수
char *p2
메모리에 있는 데이터 정보 : 1바이트 크기의 정수
void *p3
메모리에 있는 데이터 정보 : 없음
*/

//--------------------------------------------------------------

int main(void)
{

    int n = 10;

    char *p1 = &n;
    /*
    원래 메모리에는 int변수였는데
    바라보는 관점을 char로 바꾸는것
    C에서는 경고, C++에서는 컴파일 에러
    har *p1 = (char*)&n;하면 에러없다

    메모리를 해석하는 방법을 변경하는 것
    캐스팅이 필요
    */

    void *p2 = &n;
    /*
    데이터 정보 변경이 아니다.
    데이터 정보 필요없이 주소만 꺼내는 것
    캐스팅 없어도 주소를 담을 수 있다

    타입정보없이 주소만 저장하는 것
    캐스팅이 필요없다
    */
}

/*
1.명시적 캐스팅 없이 임의의 타입 변수의 주소를 담을 수 있다

2.크기를 필요로 하는 모든 연산은 사용할 수 없다.
*p2를 통해 값을 꺼내올려고하는데 타입정보가 없다
에러가 발생한다
p2 = p2 + 1;해도 error발생한다.
p2[0]; //*(p2+0)이므로 error

3.크기가 필요 없는 연산은 사용할 수 있다
==,!=,=
if( p1 == p2 ){}
*/

int main(void)
{
    int n = 10;
    char *p1 = &n;
    void *p2 = &n;

    //다른타입* = void*
    int *p3 = p2;
    char *p4 = p2;
    /*
    주소밖에 없었는데 p3로 들어가면서 나는 이거 int로 생각할게!
    주소밖에 없었는데 p4로 들어가면서 나는 이거 char로 생각할게!
    */
}

/*
void* p = &임의의타입변수;
C/C++모두 캐스팅이 필요없다.

임의타입* p = void* 변수;
C언어는 명시적 캐스팅이 필요없다
C++에서는 명시적 캐스팅이 필요

그렇지만 C에서도 명시적캐스팅을 해줘서 의도를 명확하게 보여주는 것이 좋다.
int *p3 = (int*)p2;
char *p4 = (char*)p2;
*/
