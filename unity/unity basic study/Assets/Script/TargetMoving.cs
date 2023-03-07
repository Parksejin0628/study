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
        //Debug.Log("���� ��ġ : " +  pos);
    }
}
/*
[Vector3�� ����� Ÿ���̵� �Լ���]
1. MoveTowards(���� ��ġ, ��ǥ ��ġ, �ӵ�(f)) : �ӵ��� ����Ͽ� ��ǥ��ġ���� �̵���Ų��.
2. SmoothDamp(���� ��ġ, ��ǥ ��ġ, ���� �ӵ�, �ӵ�(f)) : �ӵ��� �ݺ���Ͽ� �ε巴�� ��ǥ��ġ���� �̵��Ѵ�.
    > ���� �ӵ��� �ǽð����� �ٲ�� �ӵ��� �����Ѵٴ� �ǹ�?�̴�.
    ex) SmoothDamp(transform.position, target, ref velo, 0.2f);
3. Lerp(������ġ, ��ǥ��ġ, �ӵ�(f)) : �ӵ��� ����Ͽ� �ε巴�� ��ǥ��ġ���� �̵��Ѵ�. SmoothDamp���� ���� �ð��� ���.
    > �ӵ� �ִ밪 : 1
4. SLerp(������ġ, ��ǥ��ġ, �ӵ�(f)) : �ӵ��� ����Ͽ� �����׸��� ��ǥ��ġ���� �̵��Ѵ�.








*/
