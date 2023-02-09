using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeCycle : MonoBehaviour
{
    private void Awake()
    {
        Debug.Log("Awake : 오브젝트를 생성할 때 가장 최초로 실행된다.");
    }
    private void OnEnable()
    {
        Debug.Log("OnEnable : 오브젝트가 활성화될 때 한 번 실행된다. 오브젝트가 생성된 뒤 활성화되기 때문에 Awake 함수 바로 뒤에 호출된다.");
    }
    private void Start()
    {
        Debug.Log("Start : 업데이트 함수를 시작하기 전에 한 번 실행한다.");
    }
    private void FixedUpdate()
    {
        Debug.Log("FixedUpdate : 업데이트 함수 중 가장 먼저 실행된다. 컴퓨터 환경에 상관 없이 고정된 프레임으로 사용된다.(CPU를 많이 사용하게 된다.)주로 물리 연산과 관련된 내용을 여기에 넣는다.");
    }
    private void Update()
    {
        Debug.Log("Update : 지속적으로 실행되는 업데이트 함수이다. FixedUpdate와 다르게 컴퓨터 환경에 따라 프레임이 달라진다.");
    }
    private void LateUpdate()
    {
        Debug.Log("LateUpdate : 모든 업데이트 영역이 끝난 후 실행되는 업데이트 함수이다. 캐릭터를 쫓는 카메라 등 후처리 영역에 사용된다.");
    }
    private void OnDisable()
    {
        Debug.Log("OnDisable : 게임 오브젝트가 비활성화 될 때 실행된다. 오브젝트가 삭제되기 전에 비활성화가 먼저 되기에 삭제될 때 OnDestroy보다 빨리 실행된다.");
    }
    private void OnDestroy()
    {
        Debug.Log("OnDestroy : 게임 오브젝트가 삭제될 때 실행된다.");
    }
}
