using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyDown : MonoBehaviour
{
    private void Update()
    {
        // �ƹ�Ű�� �Է�
        if(Input.anyKey)
        {
            Debug.Log("Input.anyKey : �ƹ� Ű�� �Է����� �� ��� True�� ��ȯ�մϴ�.");
        }
        if(Input.anyKeyDown)
        {
            Debug.Log("Input.anyKeyDown : �ƹ� Ű�� ������ �� �� �� True�� ��ȯ�մϴ�.");
        }
        // Ư�� Ű �Է�
        if(Input.GetKey(KeyCode.Return))
        {
            Debug.Log("GetKey(Ű�ڵ�) : Ű�ڵ忡 �ش��ϴ� Ű�� �Է����̸� True�� ��ȯ�Ѵ�. / KeyCode.Return�� ����Ű");
        }
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            Debug.Log("GetKeyDown(Ű�ڵ�) : Ű�ڵ忡 �ش��ϴ� Ű�� ���� �� �� �� True�� ��ȯ�Ѵ�. / KeyCode.Escape�� ESC");
        }
        if(Input.GetKeyUp(KeyCode.UpArrow))
        {
            Debug.Log("GetKeyUp(Ű�ڵ�) : Ű�ڵ忡 �ش��ϴ� Ű�� �����ִ� �� �� �� �� True�� ��ȯ�Ѵ�. / KeyCode.����Arrow�� ����Ű�̴�.");
        }
        // ���콺 �Է� : ���콺�ڵ�� 0�� ��Ŭ���̴�.
        if(Input.GetMouseButton(0))
        {
            Debug.Log("GetMouseButton(���콺�ڵ�) : ���콺�ڵ忡 �ش��ϴ� ���콺��ư�� �Է����̸� True�� ��ȯ�Ѵ�.");
        }
        if(Input.GetMouseButtonDown(0))
        {
            Debug.Log("GetMouseButtonDown(���콺�ڵ�) : ���콺�ڵ忡 �ش��ϴ� ���콺��ư�� ���� �� �� �� True�� ��ȯ�Ѵ�.");
        }
        if(Input.GetMouseButtonUp(0))
        {
            Debug.Log("GetMouseButtonUp(���콺�ڵ�) : ���콺�ڵ忡 �ش��ϴ� ���콺��ư�� �����ִ� �� �� �� �� True�� ��ȯ�Ѵ�.");
        }
        // ��ư �Է� : unity������ Ư�� ��ư�� �����Ǿ��ִ�. �� ��ư�� ���δٸ� �Է���ġ�� ȣȯ�ϱ� ������ �÷����� ���ֹ��� �ʰ� ������ �� �ִٴ� ������ �������ִ�.
        // Edit > Project Settings > InputManager���� Ȯ���� �� �ִ�. Horizontal, Vertical, Jump ���� ���� ����Ѵ�.
        // InputManager���� ���� ��ư�� �����ϰų� Size�� �ø��� ���� ���Ƿ� ��ư�� �����ؼ� ����� �� �ִ�.
        if(Input.GetButton("Jump"))
        {
            Debug.Log("GetButton(��ư��) : ��ư�� ������ ���� True�� ��ȯ�Ѵ�. (��ư���� ���ڿ� ���̴�.)");
        }
        if (Input.GetButtonDown("Fire1"))
        {
            Debug.Log("GetButtonDown(��ư��) : ��ư�� ���� �� �� �� True�� ��ȯ�Ѵ�.");
        }
        if (Input.GetButtonUp("MyButton"))
        {
            Debug.Log("GetButtonUp(��ư��) : �̹� �����ִ� ��ư�� �� �� True�� ��ȯ�Ѵ�.");
        }
        
        // Horizontal, Vertical�� ���� Ⱦ, �� �̵�
        if(Input.GetButton("Horizontal"))
        {
            Debug.Log("Ⱦ �̵���..." + Input.GetAxis("Horizontal") + " / GetAxis�� ����, ������ư �Է¹��� ���� float���·� ��ȯ�Ѵ�.");
        }
        if(Input.GetButton("Vertical"))
        {
            Debug.Log("�� �̵���..." + Input.GetAxisRaw("Vertical") + "/ GetAxisRaw�� ����, ���� ��ư �Է¹��� ���� ����ġ�� ������ä -1, 0, 1���� ��ȯ�Ѵ�.");
        }

    }
}
