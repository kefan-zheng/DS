//��ͷ�ļ���������ʵ�ֵ�ջ�����У�˳�������ݽṹ����
#ifndef MYSTL_H_
#define MYSTL_H_

#include<iostream>

using namespace std;

//���
template <class Type>
class Node {
private:
	Type data;
	Node<Type>* next;
public:
	Node() { next = NULL; }
	~Node() {};
	//��ȡ�����Ϣ
	Type GetData() { return data; }
	//��ȡ�¸�����ַ
	Node<Type>* GetNext() { return next; }
	//�޸�����
	void ModifyData(Type tmp)
	{
		data = tmp;
	};
	//�޸ĵ�ַ
	void ModifyNext(Node<Type>*tmp)
	{
		next = tmp;
	}
};

//��ʽջ
template <class Type>
class LinkStack {
private:
	//ջ��Ԫ�ص�ַ
	Node<Type>* top;
	//ջ�Ĵ�С
	int size;
public:
	//��ʽջ�Ĺ��캯��(�ÿ�ջ)
	LinkStack() {
		this->top = NULL;
		this->size = 0;
	};
	//��������
	~LinkStack() {};
	//���������ջ��
	void Push(Type tmp)
	{
		Node<Type>* temp = new Node<Type>;
		temp->ModifyData(tmp);
		temp->ModifyNext(this->GetTop());
		this->top = temp;
		this->size++;
	};
	//��ջ�������굯��
	void Pop(Type& tmp)
	{
		Node<Type>* temp = this->GetTop();
		tmp = temp->GetData();
		top = top->GetNext();
		size--;
		delete temp;
	};
	//�ж�ջ�Ƿ�Ϊ��
	bool IsEmpty() {
		if (this->size > 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	//��ȡջ��Ԫ�ص�ַ
	Node<Type>* GetTop() { return top; };
	//��ȡջ�Ĵ�С
	int GetSize() { return size; }
};

//��ʽ����
template <class Type>
class MyQueue {
private:
	//����ͷβ��ַ
	Node<Type>* front;
	Node<Type>* rear;
	//���еĳ���
	int size;
public:
	//���еĹ��캯��
	MyQueue() {
		front = rear = NULL; size = 0;
	};
	//��������
	~MyQueue() {};
	//�ж϶����Ƿ�Ϊ��
	bool IsEmpty() { return (size == 0) ? 1 : 0; }
	//��ӽڵ�
	void EnQueue(Type element)
	{
		//����Ϊ��
		if (front == NULL)
		{
			front = rear = new Node<Type>;
			rear->ModifyData(element);
		}
		//���зǿ�
		else
		{
			Node<Type>* temp = new Node<Type>;
			rear->ModifyNext(temp);
			rear = rear->GetNext();
			rear->ModifyData(element);
		}
		size++;
	};
	//��ͷ����
	void DeQueue()
	{
		if (IsEmpty() == 0)
		{
			Node<Type>* temp = front;
			front=front->GetNext();
			delete temp;
			size--;
		}
	};
	//��ȡ��ͷ
	Node<Type>* GetFront() { return front; }
	//��ȡ��β
	Node<Type>* GetRear() { return rear; }
	//��ȡ���г���
	int GetSize() { return size; }
};

//˳���
template<class Type>
class MyVector {
private:
	Node<Type>* head;
	Node<Type>* tail;
	int size;
public:
	MyVector() { head = new Node<Type>;tail=head;size = 0; };
	~MyVector() {};
	//�����β
	void push_back(Type element)
	{
		Node<Type>* temph = new Node<Type>;
		tail->ModifyNext(temph);
		tail = tail->GetNext();
		temph->ModifyData(element);
		size++;
	}
	//��ȡ��numλ��Ԫ��
	Node<Type>* get_element(int num)
	{
		if (num >= size)
		{
			return NULL;
		}
		Node<Type>* temp = head->GetNext();
		while (num >= 1)
		{
			temp = temp->GetNext();
			num--;
		}
		return temp;
	};
	//����˳���Ĵ�С
	int get_size() { return size; };
};


#endif