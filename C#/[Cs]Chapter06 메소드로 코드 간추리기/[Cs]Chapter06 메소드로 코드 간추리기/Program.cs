using System;

namespace Chapter6
{
    class mainApp
    {
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

        static public ref int add2(ref int x)
        {
            x = x + 2;
            return ref x;
        }

        static void Main(string[] args)
        {
            int a = 3;
            int b = 7;

            Swap_PassByValue(a, b);
            PrintAB(a, b);
            Swap_PassByReference(ref a, ref b);
            PrintAB(a, b);

            ref int c = ref add2(ref a);
            PrintAB(a, b);
            PrintAB(c, b);
            
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






*/
