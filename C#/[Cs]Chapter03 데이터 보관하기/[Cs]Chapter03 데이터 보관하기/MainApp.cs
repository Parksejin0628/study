﻿using System;

namespace main
{
    class MainApp
    {
        static void Main(string[] args)
        {
            //정수 형식 예제
            sbyte a = -10;
            byte b = 40;

            Console.WriteLine($"a = {a}, b = {b}");

            short c = -30000;
            ushort d = 60000;

            Console.WriteLine($"c = {c}, d = {d}");

            int e = -100_0000;
            uint f = 3_0000_0000;

            Console.WriteLine($"e = {e}, f = {f}");

            long g = -5000_0000_0000;
            ulong h = 200_0000_0000_0000_0000;

            Console.WriteLine($"g = {g}, h = {h}");
        }
    }
}

/* [Chapter03 데이터 보관하기]
 * <3.1 다양한 데이터의 종류>
 *  1. C#은 데이터 처리를 위해 기본 데이터 형식과 복합 데이터 형식을 제공한다.
 *      - 기본 데이터 형식 : int, double, char, bool 등
 *      - 복합 데이터 형식 : 구조체, 클래스, 배열 등
 * <3.2 변수>
 *  1. 변수 : 값을 대입시켜 변화시킬 수 있는 요소 / 데이터를 담는 일정 크기의 공간
 *      1) 변수 사용 방법
 *          - 변수 선언 방식 : int x;
 *          - 변수 값 대입 : x = 30;
 *      2) 변수는 선언과 동시에 초기화가 가능하다.
 *          ex) int x = 30;
 *      3) 변수 여러 개를 동시에 선언 및 초기화가 가능하다. 단, 콤마로 구분해 주어야 한다.
 *          ex) int x, y, z;
 *          ex) int x = 30, y = 40, z = 50;
 *  2. C#은 변수를 초기화 하지 않으면 사용할 수 없다.
 *      - 쓰레기 값을 사용하는 것을 미연에 방지하는 것이다.
 *  3. 리터럴(Literal) : 코드에 있는 고정된 값을 지칭하는 단어이다. 주로 대입 연산자 오른쪽에 존재한다.
 *      ex) int x = 30; 에서 30이 리터럴이다.
 *      ex) string s = "가나다" 에서 "가나다"가 리터럴이다.
 * <3.3 값 형식과 참조 형식>
 *  1. 스택 영역
 *      1) 특징
 *          - 데이터를 차례대로 쌓아 저장하는 데이터 영역이다.
 *          - 특정 블록 안에서만 존재하며 '}'를 만나면 차례대로 메모리가 반환된다.
 *          - 블록 밖에서는 데이터를 사용할 수 없다는 단점이 존재한다.
 *  2. 힙 영역
 *      1) 특징
 *          - 블록에 영향을 받지 않는 데이터 영역이다.
 *          - 스택과 다르게 자동으로 메모리 반환을 하지는 않는다.
 *          - 스택 영역과 다르게 블록 밖에서도 데이터를 유지할 수 있다.
 *      2) 가비지 컬렉터(Garbage Collector) : 자동으로 메모리를 반환하지 않는 힙 영역에 단점을 보완하기 위한 CLR의 기능이다. 
 *          - 힙 영역에 있는 데이터 중 사용하지 않는다고 판단한 데이터(해당 데이터를 참조하는 곳이 없을 때)의 메모리를 반환한다.
 *  3. 데이터 저장 방식
 *      1) 값 형식(value type) : 값 그 자체를 저장하는 형식이다. 스택 영역에 저장된다.
 *      2) 참조 형식(reference type) : 변수가 값이 있는 위치를 담는 데이터 형식이다. (즉, 데이터가 담긴 곳을 참조하는 형식이다.) 
 *          - 힙 영역에 실제 사용하는 데이터를 저장한다.
 *          - 스택 영역에는 힙 영역에 있는 데이터를 가리키는 주소값을 저장한다.
 * <3.4 기본 데이터 형식>
 *  1. 정수 데이터 형식
 *      1) C#에서는 코드에 사용할 데이터의 범위에 맞춰 메모리를 효율적으로 사용할 수 있도록 다양한 숫자 데이터 형식을 제공한다. 정수 데이터 형식은 총 9가지 이다.
 *      2) 정수 데이터 형식 종류 (s 는 signed, u 는 unsigned의 줄임말이다.)
 *          - byte      : 1바이트  / 0 ~ 255
 *          - sbyte     : 1바이트  / -128 ~ 127
 *          - short     : 2 바이트 / -32,768 ~ 32,767
 *          - ushort    : 2 바이트 / 0 ~ 65,535
 *          - int       : 4 바이트 / -2,147,483,648 ~ 2,147,483,647
 *          - uint      : 4 바이트 / 0 ~ 4,294,967, 295
 *          - long      : 8 바이트 / -922,337,203,685,477,508 ~ 922,337,203,685,477,507
 *          - ulong     : 8 바이트 / 0 ~ 18,446,744,073,709,551,615
 *          - char      : 2 바이트 / 유니코드 문자
 *      3) 정수 리터럴을 타이핑 할 때 자릿수 구분자 _ 를 이용하면 편리하다.
 *          ex) x = 1000_000;
 *      4) 2진수, 16진수 리터럴을 10진수 리터럴과 구분하기 위해 2진수 앞에는 0b, 16진수 앞에는 0x 접두사를 이용한다.
 *          ex) 10의 경우 
 *                  2진수 : 0b1010
 *                  16진수 : 0xa
 *      5) 데이터 형식의 크기를 넘어선 값을 넘으면 오버플로가 발생한다. (크기보다 작은 값을 넣으면 언더플로)
 * 
 * 
 * 
 * 
 */