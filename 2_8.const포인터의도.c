//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    // c1과 c2는 완전히 동일
    const int c1 = 10;
    int const c2 = 10;

    const int c4;
    //const상수의 초기값이 없으면
    //C언어에서는 경고, C++에는 Error
    //초기화 되지 않은 const상수는 사용하지말자.
}

//2-------------------------------------------------
//그림필기
#include <stdio.h>

int main(void)
{
    int n = 10;
 
    int *p1 = &n;
    char *p2 = &n;

    const int *p3 = &n;
}
/*
★★★★★
포인터 변수를 해석하는 방법
포인터 변수가 가진 주소를 따라가면 "*연산자 앞에 있는 타입의 데이터"가 있다.

int n = 10;
int *p1 = &n;
n이 1000번지라고 가정하고 그안에 10이있다고 가정하자
p1포인터 변수안에는 1000번지가 저장되어 있다.
p1포인터 변수가 가리키는 1000번지를 가리키면 int타입의 데이터가 있다.
*/

/*
int *p1 = &n;
p1의 내용을 따라가면 "int type의 데이터"가 있을거다.

char *p2 = &n;
p2의 내용을 따라가면 "char type의 데이터"가 있을거다.
그런데 따라가면 int가 있네!
예전에도 공부했듯이 메모리를 바라보는 관점을 바꾸는 거다.
n을 char처럼 사용할게
대신에 "char *p2 = &n;"는 C에서는 경고 C++에서는 에러가 발생
명확한 의도를 위해 명시적 캐스팅하자
char *p2 = (char*)&n;

const int *p3 = &n;
p3의 내용을 따라가면 "const int type"의 데이터가 있을거다.
따라갔더니 그냥 int지 const int가 아니다.
캐스팅이 필요할지 필요없을지 생각해보자.
"char *p2 = &n;"는 메모리를 바라보는 관점을 바꾼다.
원래 n은 read와 write가 가능한데 p3를 통해 접근할때는 읽기만 할 수 있는걸로 알게!!
p3를 통해 접근하면 읽기만 할거야!
메모리를 바라보는 관점을 바꾸는게 아니라 제약을 주는거다.
캐스팅 없이 그냥 된다!
*/

#include <stdio.h>

int main(void)
{
    int n = 10;

    const int *p3 = &n;

    n = 30;//OK
    *p3 = 30;//Error
    /*
    n을통해서는 값을 바꿀수 있지만
    p3를 통해서는 읽는거만 할거지 값을 바꾸는건 사용하지 않을게!
    */
}
/*
정리
일반변수와 상수를 가리키는 포인터
상수가 아닌 일반 변수의 주소를 "상수를 가리키는 포인터"에 담을 수 있다.
=>원본은 R/W가 모두 가능하지만 포인터 변수를 통해서는 읽기만 하겠다는 의도다.
*/