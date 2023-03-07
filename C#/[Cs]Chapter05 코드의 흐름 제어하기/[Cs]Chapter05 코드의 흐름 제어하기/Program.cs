using System;

namespace Chapter05
{
    class Program
    {
        static void Main(string[] args)
        {
            //switch문 데이터 형식 분류 실습
            object obj = true;
            switch(obj)
            {
                case int i when i >= 5:
                    Console.WriteLine($"int형이며 값이 5 이상입니다.{i}");
                    break;
                case int i:
                    Console.WriteLine("{0} int형이며 값이 4 이하입니다.", i);
                    break;
                case float f:
                    Console.WriteLine($"float형입니다.<f>");
                    break;
                case string s:
                    Console.WriteLine("string형입니다." + s);
                    break;
                default:
                    Console.WriteLine("int, float, string 외의 형입니다.");
                    break;
            }

            //switch식 실습
            int score = 80;
            bool repeated = false;
            string grade = score switch
            {
                90 when repeated => "A+",
                90 => "A",
                80 => "B",
                70 => "C",
                _ => "F"
            };
            Console.WriteLine("당신의 성적은 " + grade + "입니다.");

            //foreach 실습
            int[] arr = { 10, 20, 30, 40, 50 };
            foreach(int i in arr)
            {
                Console.WriteLine(i);
            }
            //goto 실습 goto전에 레이블이 있으면 아에 코드에서 인식을 못한다. goto밑에 있는 레이블만 인식한다.
            
            Console.WriteLine("goto 전");
            goto JUMP;
            Console.WriteLine("과연 점프가 될까요?");
        JUMP:
            Console.WriteLine("점프 완료");
            SolvingQuestion1();
            SolvingQuestion2();
            SolvingQuestion3();
            SolvingQuestion4();
        }

        public static void SolvingQuestion1()
        {
            for(int i=0; i<5; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            return;
        }

        public static void SolvingQuestion2()
        {
            for(int i=0; i<5; i++)
            {
                for (int j = 0; j < 5 - i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            return;
        }

        public static void SolvingQuestion3()
        {
            int i = 0, j = 0;

            while(i < 5)
            {
                j = 0;
                do
                {
                    Console.Write("*");
                    j++;
                } while (j <= i);
                Console.WriteLine();
                i++;
            }
            i = 0;
            j = 0;
            while (i < 5)
            {
                j = 0;
                while (j < 5 - i)
                {
                    Console.Write("*");
                    j++;
                }
                Console.WriteLine();
                i++;
            }
            return;
        }

        public static void SolvingQuestion4()
        {
            int repeat = 0;

            Console.Write("반복 횟수를 입력하세요 : ");
            repeat = Convert.ToInt32(Console.ReadLine());
            if (repeat <= 0)
            {
                Console.WriteLine("0보다 작거나 같은 수는 입력할 수 없습니다.");
            }

            for(int i=0; i<repeat; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            

            return;
        }
    }
}
/*
[Chapter05 코드의 흐름 제어]
<5.1 분기문>
1. if문
 1) if(조건식) { ... } : 조건식이 참이라면 괄호 안을 실행한다.
 2) else if(조건식) { ... } : 위 if문의 조건이 거짓일 경우 조건식을 검사한다. 조건식이 참이라면 괄호 안을 실행한다.
 3) else { ... } : 위 if문, else if문이 모두 거짓일 경우 괄호 안을 실행한다.
 4) if문 안에 if문을 중첩해서 사용할 수 있다.
    ex) if(조건식1) { ... if(조건식2) { ... } }
2. switch 문
 1) switch문의 기본 모양
    switch(조건식)            조건식의 결과가 가질 수 있는 다양한 값에 대해 대응하도록 한다.
    {
        case 상수1:           조건식의 결과가  상수1인 경우 break까지 코드를 실행하고 괄호 밖으로 빠져나간다.
            ...
            break;
        case 상수2:           조건식의 결과가  상수2인 경우 break까지 코드를 실행하고 괄호 밖으로 빠져나간다.
            ...
            break;
        ...
        default:              위 case에 해당하는 것이 없을 경우 break까지 코드를 실행하고 괄호 밖으로 빠져나간다.
            ...
            break;
    }
 2) switch문의 조건식에는 정수 형식, 문자열 형식을 사용할 수 있다.
 3) C# 7.0 부터는 switch 문에 데이터 형식을 조건으로 사용할 수 있게 되었다. (object)
    ex) obj object = 7;
    switch (obj)
    {
        case int i:     obj가 int형식이므로 i가 obj역할을 하며 break까지 문장이 실행된다.
            ...
            break;
        case float f:
            ...
            break;
        ...
        default:
            ...
            break;
    }
 4) 데이터 형식에 따라 분기하는 switch문에 when 절을 이용해 추가적인 조건 검사를 할 수 있다.
    ex) case int i when i >= 3:
3. switch 식
 1) 문과 식의 차이 : 어떤 일을 하는 것을 문(조건문, 반복문)이라고 하고 어떤 결과를 내놓는 것은 식(조건식 등)이라고 한다.
 2) switch 식은 분기에 거쳐 값을 내야 하는 경우에 특화되어있다. (가독성이 더 좋다.)
 3) switch 문에서 조건식을 switch 키워드 앞으로 보내고 case: 는 =>로 break는 ,로 default는 _로바꾸면 switch문이 탄생한다.
    ex) score 값에 따라 grade값이 결정되는 switch 식이다.
    string grade = score switch             scroe 값에 따라 grade 값 대입
    {
        90 when repeated == true => "B+",   score가 90이고 repeated변수가 true인 경우 "B+" 저장
        90 => "A",                          score가 90인 경우 "A" 저장 (score가 90인데 repeated가 true면 위에를, 아니면 이 문장을 실행)
        80 => "B",                          score가 80인 경우 "B" 저장
        70 => "C",                          score가 70인 경우 "C" 저장
        _ => "F"                            위가 모두 아닌 경우 "F" 저장
    }; 식이라서 그런지 세미콜론이 붙는다!

<5.2 반복문>
 1. while
  1) 기본 형태 : while(조건식) { ... }
  2) 기능 : 조건식이 참일 동안 괄호 안을 반복한다.
 2. do while
  1) 기본 형태 : do { ... } while(조건식);
  2) 기능 : 괄호 안을 실행한 후 조건식이 참이면 반복한다. (일단 한 번은 실행한다.)
  3) 특징 : while문 뒤에 세미콜론(;)이 붙어야 한다.
 3. for
  1) 기본 형태 : for(초기화식; 조건식; 반복식) { ... }
  2) 기능 : 초기화식을 실행한다. 그 후 조건식 검사 > 반복 > 반복식 실행 > 조건식 검사 ... 를 조건식이 참일 동안 반복한다.
 4. foreach
  1) 기본 형태 : foreach (데이터형식 변수명 in 배열 혹은 컬렉션)
        ex) foreach(int i in arr) { Console.WriteLine(i) } (arr은 변수, i는 배열 요소이다. (arr[i]의 역할이라고 생각하면 된다.))
  2) 기능 : 배열을 순회하며 반복한다.

<5.3. 점프문>
 1. break : 반복문이나 switch 문의 실행을 중단할 때 사용한다.
 2. continue : 반복문에서 이번 반복만 건너뛰게 할 때 사용한다.
    - continue문을 사용하면 아랫 줄을 더 읽어보지 않아도 실행이 취소됨을 알 수 있기에 가독성이 훨씬 좋아진다. 좋은 코드가 된다.
 3. goto
  1) 기본 형태 : goto 레이블;
  2) 기능 : 레이블로 이동한다.
    - 레이블은 위치를 나타내는 존재로 세미콜론이 아닌 콜론을 붙여 사용한다.
  3) 예시
    goto JUMP; 문장1 JUMP: 문장2 코드가 있을 경우 문장1은 생략되고 JUMP:로 이동하여 문장2가 실행된다.
 4. return, throw는 추후에 다룬다.


*/