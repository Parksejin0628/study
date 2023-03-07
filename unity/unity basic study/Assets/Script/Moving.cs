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
 - ��� ������Ʈ�� ������ Transform�� ������. ����, unity������ ���� �������� �ʾƵ� Transform���� transform�̶�� ������ �����Ǿ��ִ�.
 - transform.Translate() : ������ ���� ���� ���� ��ġ ���� ���ϴ� �Լ��̴�.
 - Vector3 �� x, y, z���� ������ ��ü�̴�.
    > ���� ��� : Vetcor3 vector = new Vector(1, 2, 3);
 - Time.deltaTime�� ����ϸ� ��ǻ�� ���ɰ� ������� ������ ��ġ�� �̵��� �� �ִ�.
    > Time.deltaTime ���� �������� Ŀ���� �۾�����, �������� �۾����� Ŀ����.
    > Translate���� ���Ϳ� ���ϰ� Vector�Լ��� ���ǵ�(�ð�) �Ű������� ���Ѵ�.





*/
