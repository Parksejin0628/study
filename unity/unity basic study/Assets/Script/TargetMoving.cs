using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetMoving : MonoBehaviour
{
    public int num = 1;
    public float speed = 0.5f;
    public Vector3 target = new Vector3(0, 0, 4);
    public Vector3 velo = Vector3.zero;
    private Vector3 pos = Vector3.zero;
    // Update is called once per frame
    void Update()
    {
        pos = transform.position;
        if(num == 1)
        {
           pos = Vector3.MoveTowards(pos, target, speed);
        }
        else if(num == 2)
        {
            pos = Vector3.SmoothDamp(pos, target, ref velo, speed);
        }
        else if(num == 3) 
        {
            pos = Vector3.Lerp(pos, target, speed);        
        }
        else
        {
            pos = Vector3.Slerp(pos, target, speed);
        }
        transform.position = pos;
        //Debug.Log("현재 위치 : " +  pos);
    }
}
/*
[Vector3에 내장된 타겟이동 함수들]
1. MoveTowards(현재 위치, 목표 위치, 속도(f)) : 속도에 비례하여 목표위치까지 이동시킨다.
2. SmoothDamp(현재 위치, 목표 위치, 참조 속도, 속도(f)) : 속도에 반비례하여 부드럽게 목표위치까지 이동한다.
    > 참조 속도는 실시간으로 바뀌는 속도를 적용한다는 의미?이다.
    ex) SmoothDamp(transform.position, target, ref velo, 0.2f);
3. Lerp(현재위치, 목표위치, 속도(f)) : 속도에 비례하여 부드럽게 목표위치까지 이동한다. SmoothDamp보다 감속 시간이 길다.
    > 속도 최대값 : 1
4. SLerp(현재위치, 목표위치, 속도(f)) : 속도에 비례하여 원을그리며 목표위치까지 이동한다.








*/
