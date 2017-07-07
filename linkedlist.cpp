#include <iostream>
#include <vector>

using namespace std;
struct Node{
	int data;
	Node *next;
};

class LinkedList{
private:
	Node *head;
	Node *tail;
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
	}

	Node *get_head_ll(){
		return head;
	}

	Node *get_tail_ll(){
		return tail;
	}

	void push_back_ll(int data){
		Node *temp = new Node;
		temp->data = data;
		temp->next = NULL;
		if(head == NULL){
			head = temp;
			tail = temp;
		}else{
			tail->next = temp;
			tail = temp;
		}
	}

	void print_ll(){
		Node *temp = new Node;
		temp = head;
		while(temp != NULL){
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}

	int size_ll(){
		Node *temp = new Node;
		temp = head;
		int i  =0;
		while(temp != NULL){
			temp = temp->next;
			i++;
		}
		return i;
	}

	void insert_start_ll(int value){
		Node *temp = new Node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}

	void insert_at_ll(int pos, int value){
		Node *pre = new Node;
		Node *cur = new Node;
		Node *temp = new Node;

		cur = head;
		for(int i=1; i<pos; i++){
			pre = cur;
			cur = cur->next;
		}

		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}

	int get_at_ll(int pos){
		Node *pre = new Node;
		Node *cur = new Node;
		Node *temp = new Node;

		cur = head;
		for(int i=0; i<pos; i++){
			pre = cur;
			cur = cur->next;
		}

		return cur->data;
	}

	void delete_first_ll(){
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void delete_last_ll(){
		Node *current = new Node;
		Node *previous = new Node;
		while(current->next != NULL){
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}

	void clear_ll(){
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		while(current->next != NULL){
			previous = current;
			current = current->next;
			delete previous;
		}
		delete current;
		head = NULL;
		tail = NULL;
	}

	void delete_position_ll(int pos){
		Node *current = new Node;
		Node *previous = new Node;

		current = head;
		for(int i=1; i<pos; i++){
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		//delete current;
	}
	void delete_position2_ll(int pos){
		if(head == NULL)
			return;
		Node *temp = new Node;
		temp = head;
		if(pos == 0){
			head = temp->next;
			delete(temp);
			return;
		}
		for(int i=0; temp!=NULL && i<pos-1; i++){
			temp = temp->next;
		}

		if(temp==NULL || temp->next==NULL){
			return;
		}
		Node *next = temp->next->next;
		delete(temp->next);
		temp->next = next;
	}
	//hard copy of memory
	void copy_ll(LinkedList l){
		Node *current = new Node;
		current = l.get_head_ll();

		while(current != NULL){
			std::cout << "am in copy " << current->data << std::endl;
			push_back_ll(current->data);
			current = current->next;
		}
	}

};

/*
int main(){
	LinkedList l, m;
	l.push_back_ll(5);
	l.push_back_ll(2);
	l.push_back_ll(9);

	l.insert_start_ll(99);
	l.insert_at_ll(3, 77);
    std::cout << "print all " << std::endl;
	l.print_ll();
	std::cout << "print after delete " << std::endl;
	l.delete_position2_ll(0);
	l.print_ll();

/*
	std::cout << "lets do copy on ll --> m" << std::endl;
	m.copy_ll(l);
	std::cout << "copy done  ll --> m" << std::endl;

	l.push_back_ll(55);
    	std::cout << "print ll ==== l" << std::endl;
	l.print_ll();
	std::cout << "print ll ==== m" << std::endl;
	m.print_ll();

	std::cout << "size of ll ==== m = " << m.size_ll()<< std::endl;

	m.clear_ll();
	std::cout << "after delete " << std::endl;
	m.print_ll();
	std::cout << "testing get 	" << l.get_tail_ll()->data << std::endl;
	std::cout << "get at postion 	" << l.get_at_ll(5) << std::endl;

	std::cout << "testing vectors "  << std::endl;
	std::vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::cout << "get value at postion 2=v[2]  " << v[2]  << std::endl;
	std::vector<int> u(3);
	u = v;
	v.push_back(8);
	for(std::vector<int>::iterator i = u.begin(); i!=u.end(); i++){
		std::cout << *i << std::endl;
	}

	return 0;
}
*/
