using System;
using System.Transactions;

namespace Chapter6
{
    class mainApp
    {
        //6.4 참조에 의한 매개변수 전달
        static public void Swap_PassByValue(int x, int y)
        {
            int temp = x;
            x = y;
            y = temp;

            return;
        }

        public static void Swap_PassByReference(ref int x, ref int y)
        {
            int temp = x;
            x = y;
            y = temp;

            return;
        }


        static public void PrintAB(int a, int b)
        {
            Console.WriteLine("a : " + a);
            Console.WriteLine("b : " + b);
        }
        //6.5 메소드의 결과를 참조로 반환하기
        static public ref int add2(ref int x)
        {
            x = x + 2;
            return ref x;
        }
        //6.6. 출력 전용 매개변수
        static private void DoubleUp(int a, int b, out int c, out int d)
        {
            c = a * 2;
            d = b * 2;
        }
        //6.8. 가변 개수의 인수
        static private int Sum(params int[] x)
        {
            int sum = 0;
            for(int i=0; i<x.Length; i++)
            {
                sum += x[i];
            }

            return sum;
        }

        static double Square(double arg)
        {
            return arg * arg;
        }


        static void Main(string[] args)
        {
            int a = 3;
            int b = 7;
            //6.4 참조에 의한 매개변수 전달
            Swap_PassByValue(a, b);
            PrintAB(a, b);
            Swap_PassByReference(ref a, ref b);
            PrintAB(a, b);
            //6.5 메소드의 결과를 참조로 반환하기
            ref int c = ref add2(ref a);
            PrintAB(a, b);
            PrintAB(c, b);
            //6.6. 출력 전용 매개변수
            DoubleUp(a, b, out int i, out int j);
            PrintAB(i, j);

            //6.8. 가변 개수의 인수
            int d = Sum(1, 2, 5, 7, 8, 11);
            Console.WriteLine(d);

            //연습문제 1
            Console.Write("수를 입력하세요 : ");
            string input = Console.ReadLine();
            double arg = Convert.ToDouble(input);

            Console.WriteLine("결과 : {0}", Square(arg));

        }
    }
}



/*
[Chapter06 메소드로 코드 간추리기]
<6.1. 메소드란?>
1. 메소드 : 일련의 코드를 하나의 이름 아래 묶은 것
    1) 선언 형식
        - 한정자 반환형식 메소드이름(매개변수)
        - 한정자는 private, public과 같은 속성을 수식하는 것을 의미한다.
            ex) public static int Plus(int a, int b) 에서 public static이 한정자, int가 반환형, Plus가 메소드이름, int a int b가 매개변수이다.
    2) 메소드가 함수, 프로시저, 서브루틴 등과 다른 점은 '클래스 안'에 존재한다는 것이다.
2. 매개변수와 인수의 차이점
    - 인수 : 메소드를 호출한 곳에서 매개변수에 '넘기는 값' 이다.
    - 매개변수 : 호출자로부터 전달받는 값을 '받는 변수' 이다.
3. static 한정자 : static 한정자를 지정함으로써 메소드를 클래스 자체에 소속하도록 한다.
    - 이는 인스턴스(객체)를 만들지 않고도 해당 메소드를 호출할 수 있다는 의미이다.

<6.2. return에 대하여>
1. return은 프로그램의 흐름을 메소드에서 호출자로 돌려놓는 점프문이다.
2. 반환값을 전달할 수 있다.

<6.3. 매개변수에 대하여>
1. 매개변수도 변수이다.
2. 메소드를 호출할 때 매개변수를 선언하면서 인자값을 대입하는 형식으로 진행이 된다.
    ex) int a, int b를 매개변수로 가진 메소드를 func(x, y)와 같은 형태로 전달하면 매개변수는 int a = x; int b = y;와 같은 방식으로 매개변수가 선언되는 것이다.
3. 따라서, 값에 의한 전달로는 메소드내에서 호출자의 변수를 변경할 수 없다.

<6.4. 참조에 의한 매개변수 전달>
1. 메소드 내에서 호출자의 변수를 변경하기 위해서는 참조에 의한 매개변수 전달(pass by reference)를 해야한다.
2. C#에서 pass by reference를 위해서는 매개 변수 앞에 ref를 붙이면 된다.
    ex) public static int func(ref int a, int b);
3. 참조에 의한 매개변수 전달을 할 때에는 호출에도 인자 앞에 ref를 붙여야 한다.
4. C#에서는 포인터를 이용하지 않는다! (가능은 하나 추천하지는 않는다.)

<6.5. 메소드의 결과를 참조로 반환하기>
1. 참조로 반환하기 위한 메소드 선언
    1) 참조 반환값(ref return)을 가지는 메소드를 선언하기 위해서는 함수 선언에 ref 한정자를 명시하고 return 바로 뒤에 ref를 붙여야 한다.
        ex) public ref int method()
            {
                ...
                return ref value;
            }
2. 참조 반환값을 받기 위한 참조 지역 변수
    1) 참조 반환값을 받기 위해서는 ref 키워드를 앞에 위치한 참조 지역 변수가 있어야 한다.
        - C++처럼 선언과 동시에 무언가를 참조해야 하는 것으로 보인다.
        ex) ref int a = 참조대상
    2) 함수를 호출할 때 앞에 ref를 붙여야 한다.
        ex) ref int a = ref method();

<6.6. 출력 전용 매개변수>
1. 메소드로 부터 여러 개의 결과값을 받아오고 싶다면 pass by reference를 사용하는 방법이 좋은 방법 중 하나이다.
2. ref를 사용해도 되지만 C#에는 pass by reference로 결과값을 가져오는 것에 특화된 키워드가 있는데 out 키워드이다.
    1) out : 출력 전용 매개변수를 나타내는 키워드
    2) 사용방법 : 호출 시 인자와 매개변수 앞에 ref 대신 out 키워드를 작성하면 된다.
        ex) public static method(int a, int b, out int c, out int d);
            ...
            method(x, y, out i, out j);
    3) out의 기능 : out 키워드를 사용한 매개변수에 값을 저장하지 않으면 컴파일 에러가 발생한다.
        - 개발자의 실수로 값을 저장하지 않는 것을 컴파일 단계에서 확인시켜주기에 버그 방지 효과가 있다.
3. 출력 전용 매개변수는 메소드를 호출하면서 선언해도 된다.
    ex) divide(a, b, out int c, out int d);

<6.7. 메소드 오버로딩>
1. 메소드 오버로딩
    1) 메소드 오버로딩 : 하나의 메소드 이름에 여러 개의 구현을 하는 것
    2) 매개변수의 수와 형식에 따라 다른 버전의 메소드를 호출해준다.
        - 반환 형식은 구별할 방법이 없으므로 구별하지 않는다.
        ex) public static int func(int a, int b) / public static int func(int a) / public static int func(double a, double b) 모두 메소드 오버라이딩 가능
    3) 유연한 메소드 제공이 가능하여 생산성을 높여준다.

<6.8. 가변 개수의 인수>
1. 가변 개수의 인수 : 개수가 유연하게 변할 수 있는 인수
    1) 사용법 : 매개변수 앞에 params를 붙이고 매개변수를 배열로 선언한다.
        ex) int Sum(params int[] args) { ... }
    2) 활용법 : 인수의 개수만 유연하게 달라질 수 있는 함수에 사용하기 좋다.
2. 다른 매개변수와 이용할 때는 가변 개수의 인수가 무조건 마지막에 있어야 한다.

<6.9. 명명된 인수>
1. 명명된 인수
    1) 정의 : 메소드를 호출할 때 순서가 아닌 인수의 이름으로 데이터를 할당할 수 있는 기능
    2) 사용법 : '인수명 : 전달할 데이터 값'
        ex) PrintProfile(name : "박세진", phone : "010-2708-3709");
    3) 순서에 의존할 필요가 없으며 코드의 가독성을 높여준다.

<6.10. 선택적 인수>
1. 선택적 인수
    1) 정의 : 매개변수에 기본 값을 선언하여 인수를 선택적으로 받는 것
    2) 사용법 : 함수 선언에서 매개변수에 초기값을 대입하면 된다.
        ex) public static int fuc(int a, int b = 3);
    3) 주의점 : 선택적 인수는 항상 필수 인수 뒤에 와야 한다. 즉, 기본 값을 가진 매개변수가 없는 매개변수 앞에 있어선 안된다.
    4) 활용 : 매개변수에 기본 값을 선언한 경우 그 인수는 전달하지 않아도 기본값으로 메소드가 실행된다.
    5) 코드 유지보수 단계에서 헷갈릴 가능성이 있으므로 명명된 인수와 함께 사용하면 유용하다.

<6.11. 로컬 함수>
1. 로컬 함수
    1) 정의 : 메소드 안에서 선언되고 메소드 안에서만 사용 가능한 함수이다.
    2) 특징 : 자신이 존재하는 지역의 변수를 사용할 수 있다.
    3) 활용 : 특정 메소드 안에서만 반복적으로 사용 되는 것을 로컬 함수로 정의하여 코드를 간추릴 수 있다.

*/
