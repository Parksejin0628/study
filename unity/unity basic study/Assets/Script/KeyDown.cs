using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyDown : MonoBehaviour
{
    private void Update()
    {
        // 아무키나 입력
        if(Input.anyKey)
        {
            Debug.Log("Input.anyKey : 아무 키나 입력중일 때 계속 True를 반환합니다.");
        }
        if(Input.anyKeyDown)
        {
            Debug.Log("Input.anyKeyDown : 아무 키나 눌렀을 때 한 번 True를 반환합니다.");
        }
        // 특정 키 입력
        if(Input.GetKey(KeyCode.Return))
        {
            Debug.Log("GetKey(키코드) : 키코드에 해당하는 키가 입력중이면 True를 반환한다. / KeyCode.Return이 엔터키");
        }
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            Debug.Log("GetKeyDown(키코드) : 키코드에 해당하는 키가 눌릴 때 한 번 True를 반환한다. / KeyCode.Escape가 ESC");
        }
        if(Input.GetKeyUp(KeyCode.UpArrow))
        {
            Debug.Log("GetKeyUp(키코드) : 키코드에 해당하는 키가 눌려있다 땔 때 한 번 True를 반환한다. / KeyCode.방향Arrow가 방향키이다.");
        }
        // 마우스 입력 : 마우스코드는 0이 좌클릭이다.
        if(Input.GetMouseButton(0))
        {
            Debug.Log("GetMouseButton(마우스코드) : 마우스코드에 해당하는 마우스버튼이 입력중이면 True를 반환한다.");
        }
        if(Input.GetMouseButtonDown(0))
        {
            Debug.Log("GetMouseButtonDown(마우스코드) : 마우스코드에 해당하는 마우스버튼이 눌릴 때 한 번 True를 반환한다.");
        }
        if(Input.GetMouseButtonUp(0))
        {
            Debug.Log("GetMouseButtonUp(마우스코드) : 마우스코드에 해당하는 마우스버튼이 눌려있다 땔 때 한 번 True를 반환한다.");
        }
        // 버튼 입력 : unity에서는 특정 버튼이 설정되어있다. 각 버튼은 서로다른 입력장치에 호환하기 때문에 플랫폼에 구애받지 않고 개발할 수 있다는 장점을 가지고있다.
        // Edit > Project Settings > InputManager에서 확인할 수 있다. Horizontal, Vertical, Jump 등을 많이 사용한다.
        // InputManager에서 기존 버튼을 수정하거나 Size를 늘리면 내가 임의로 버튼을 지정해서 사용할 수 있다.
        if(Input.GetButton("Jump"))
        {
            Debug.Log("GetButton(버튼명) : 버튼을 누르는 동안 True를 반환한다. (버튼명은 문자열 값이다.)");
        }
        if (Input.GetButtonDown("Fire1"))
        {
            Debug.Log("GetButtonDown(버튼명) : 버튼을 누를 때 한 번 True를 반환한다.");
        }
        if (Input.GetButtonUp("MyButton"))
        {
            Debug.Log("GetButtonUp(버튼명) : 이미 눌려있는 버튼을 땔 때 True를 반환한다.");
        }
        
        // Horizontal, Vertical을 통한 횡, 종 이동
        if(Input.GetButton("Horizontal"))
        {
            Debug.Log("횡 이동중..." + Input.GetAxis("Horizontal") + " / GetAxis는 수평, 수직버튼 입력받은 것을 float형태로 반환한다.");
        }
        if(Input.GetButton("Vertical"))
        {
            Debug.Log("종 이동중..." + Input.GetAxisRaw("Vertical") + "/ GetAxisRaw는 수평, 수직 버튼 입력받은 것을 가중치를 무시한채 -1, 0, 1만을 반환한다.");
        }

    }
}
