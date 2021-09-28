#include <stdio.h>

int main(void)
{
    char s1[] = "Hello";
    char *s2 = "Hello";

    *s1 = 'A';
    //*s2 = 'A';

    printf("%s\n", s1);
    printf("%s\n", s2);
}
//그림필기
/*
*s2 = 'A';에서 런타임 에러가 난다
위의코드실행하면 출력되지 않고 그냥 죽는다
s2가 상수메모리이기 때문이다

"//*s2 = 'A';"와 같이 주석처리하면 실행된다.

그런데 cl 컴파일러에서 컴파일하면 아무문제 없이 실행된다
cl 컴파일러는 *s2가 가리키는 "Hello"를 .data에 놓는다
이건 1_13을 참고
*/

/*
char *s2 = "Hello";라는 뜻은 
읽기만 하게 만들고 싶다는 뜻이다.

그러므로!
const char *s2 = "Hello";
이게 좋은 코드이다.

const char상태에서
"*s2 = 'A';"사용하면
런타임에러가아니라 컴파일에러가 발생한다.
*/

/*
문자열을 포인터를 만들때는 char*가 아닌
const char*를 사용하는 것이 좋다.
*/