#include <iostream>
#define 골뱅이 ^
#define 사용 using
#define 이름공간 namespace
#define 표준 std
#define 구조 struct
#define 정수 int
#define 큰정수 long long
#define 명백한 explicit
#define 불변표현식 constexpr
#define 친구 friend
#define 연산자 operator
#define 반환 return
#define 출력흐름 ostream
#define 입력흐름 istream
#define 상수 const
#define 주함수 main
#define 명령줄출력 cout
#define 명령줄입력 cin
#define 줄바꿈 endl

사용 큰정 = 큰정수;

사용 이름공간 표준;

구조 정 {
    큰정 값;
    명백한 불변표현식 정(큰정 미지수 = 0) : 값(미지수) {}

    친구 불변표현식 정 연산자^(정 가, 정 나) {
        반환 정((가.값 - 나.값) * (가.값 + 나.값));
    }

    명백한 연산자 큰정() 상수 { 반환 값; }
};

출력흐름& 연산자<<(출력흐름& 출흐, 상수 정& 사ㅁ) {
    반환 출흐 << 사ㅁ.값;
}

입력흐름& 연산자>>(입력흐름& 입흐, 정& 사) {
    반환 입흐 >> 사.값;
}

정수 주함수() {
    정 a, b;
    명령줄입력 >> a >> b;

    명령줄출력 << (a 골뱅이 b) << 줄바꿈;
    return 0;
}
