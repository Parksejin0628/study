using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ForceMoving : MonoBehaviour
{
    private Rigidbody rigidbody;
    public Vector3 vec;
    // Start is called before the first frame update
    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {

        vec = new Vector3(Input.GetAxisRaw("Horizontal"), 0, Input.GetAxisRaw("Vertical"));

        rigidbody.AddForce(vec * 2);
    }
}
