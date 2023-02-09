using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeCycle : MonoBehaviour
{
    private void Awake()
    {
        Debug.Log("Awake : ������Ʈ�� ������ �� ���� ���ʷ� ����ȴ�.");
    }
    private void OnEnable()
    {
        Debug.Log("OnEnable : ������Ʈ�� Ȱ��ȭ�� �� �� �� ����ȴ�. ������Ʈ�� ������ �� Ȱ��ȭ�Ǳ� ������ Awake �Լ� �ٷ� �ڿ� ȣ��ȴ�.");
    }
    private void Start()
    {
        Debug.Log("Start : ������Ʈ �Լ��� �����ϱ� ���� �� �� �����Ѵ�.");
    }
    private void FixedUpdate()
    {
        Debug.Log("FixedUpdate : ������Ʈ �Լ� �� ���� ���� ����ȴ�. ��ǻ�� ȯ�濡 ��� ���� ������ ���������� ���ȴ�.(CPU�� ���� ����ϰ� �ȴ�.)�ַ� ���� ����� ���õ� ������ ���⿡ �ִ´�.");
    }
    private void Update()
    {
        Debug.Log("Update : ���������� ����Ǵ� ������Ʈ �Լ��̴�. FixedUpdate�� �ٸ��� ��ǻ�� ȯ�濡 ���� �������� �޶�����.");
    }
    private void LateUpdate()
    {
        Debug.Log("LateUpdate : ��� ������Ʈ ������ ���� �� ����Ǵ� ������Ʈ �Լ��̴�. ĳ���͸� �Ѵ� ī�޶� �� ��ó�� ������ ���ȴ�.");
    }
    private void OnDisable()
    {
        Debug.Log("OnDisable : ���� ������Ʈ�� ��Ȱ��ȭ �� �� ����ȴ�. ������Ʈ�� �����Ǳ� ���� ��Ȱ��ȭ�� ���� �Ǳ⿡ ������ �� OnDestroy���� ���� ����ȴ�.");
    }
    private void OnDestroy()
    {
        Debug.Log("OnDestroy : ���� ������Ʈ�� ������ �� ����ȴ�.");
    }
}
