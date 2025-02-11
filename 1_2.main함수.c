/*
1.
main함수 적을때
int main(void)
int main()
void main(void)
void main()

뭐가 맞는거지??
*/

/*
2.
▣C언어가 표준화 되기 이전에 사용하던 main함수 모양
main() { }
int main() { }

즉 void라는 키워드가 없었음

▣C언어 표준화 이후(C89,C99,C11)
int main(void) { }
int main(int argc, char*argv[]) { }

▣C++언어 표준(C++98/C++03/C++11/C++14/C++17)
int main() { }
int main(int argc, char*argv[]) { }
*/

#include <stdio.h>

int main(void)
{
    printf("Hello C\n");
}

/*
3.
C언어에서 void없이 아래처럼 적어서 컴파일해도 문제없긴하다.
"int main() { }"
gcc main.c -Wall
위의 명령은 모든 경고를 보여달라는 건데
경고조차 안나온다.

"void main(void) { }"
컴파일해도 문제없긴하다.
gcc main.c -Wall
이렇게 하면 반환값은 int가 되야한다는 경고는 나온다.
*/

/*
4.
일부 운영체제 환경에서 추가적인 main함수 모양

▣Unix/linux 환경에서 gcc
int main(int argc, char*argv[], char *envp[]) { }

▣Windows 환경 visual studio(cl compiler)
int main(int argc, char*argv[], char *envp[]) { }

▣OSX
int main(int argc, char*argv[], char *envp[], char *apple[]) { }
*/