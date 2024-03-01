using System;

namespace Chapter08
{
    class MainApp
    {
        static void Main(string[] args)
        {

        }
    }
}

/*
[Chapter08 인터페이스와 추상 클래스]
<8.1. 인터페이스의 선언>
1. 인터페이스의 선언
    1) 인터페이스는 interface 키워드를 이용해 선언하며 마치 클래스처럼 선언한다.
    2) 예시
        interface InterfaceName
        {
            int method1(int a);
            float method2(int b, string c);
        }
2. 인터페이스의 특징
    1) 메소드, 이벤트, 인덱서, 프로퍼티를 제외한 어떤 멤버도 가질 수 없다.
        - 즉, 변수를 가지지 않는다!
    2) 메소드 등은 선언부만 존재할 수 있으며 접근 제한 한정자를 사용할 수 없다.
        - 모든 멤버가 public으로 선언하며 구현부는 존재하지 않는다.
    3) 다른 클래스가 인터페이스를 상속할 수 있으며 인터페이스를 상속한 클래스는 반드시 인터페이스의 메소드를 구현하고 public으로 수식해야 한다.
    4) 인터페이스 자체는 인스턴스를 가질 수 없으나 인터페이스를 상속한 클래스를 통해 인스턴스를 만들 수 있다.
 */