using JetBrains.Annotations;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class Moving : MonoBehaviour
{
    public float SPEED = 0.1f;
    void Update()
    {
        Vector3 vec = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical")) * SPEED;
        transform.Translate(vec * Time.deltaTime);
    }
}
/*
 - 모든 오브젝트는 무조건 Transform을 가진다. 따라서, unity에서는 따로 선언하지 않아도 Transform변수 transform이라는 변수가 생성되어있다.
 - transform.Translate() : 전달한 벡터 값을 현재 위치 값에 더하는 함수이다.
 - Vector3 는 x, y, z값을 가지는 객체이다.
    > 선언 방식 : Vetcor3 vector = new Vector(1, 2, 3);
 - Time.deltaTime을 사용하면 컴퓨터 성능과 상관없이 동일한 위치를 이동할 수 있다.
    > Time.deltaTime 값은 프레임이 커지면 작아지고, 프레임이 작아지면 커진다.
    > Translate에는 벡터에 곱하고 Vector함수는 스피드(시간) 매개변수에 곱한다.





*/
