// My Recursive solution (Knowledge Centre)
Node *solve(Node *head){
    Node *curr=head,*tail=head;
    while(curr){
        Node *child=curr->child;
        Node *next=curr->next;
        if(child){
            Node *_tail=solve(child);
            _tail->next=next;
            if(next){
                next->prev=_tail;
            }
            curr->next=child;
            child->prev=curr;
            curr->child=NULL;
            curr=tail;
        }
        else{
            curr=next;
        }
        if(curr!=NULL){
            tail=curr;            
        }
    }
    return tail;
}
Node* flatten(Node* head) {
    if(head){
        solve(head);
    }
    return head;
}

// Iterative solution (Fast solution)
Node* flatten(Node* head) {
	for (Node* h = head; h; h = h->next)
	{
		if (h->child)
		{
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
}
//Recursive New Type
Node* flatten(Node* head, Node* rest = nullptr) {
  if (!head) return rest;
  head->next = flatten(head->child, flatten(head->next, rest));
  if (head->next) head->next->prev = head;
  head->child = nullptr;
  return head;
}
/*
This function modifies the structure in place. It's not the fastest implementation out there, but I love short recursive algorithms, and I thought this was rather nice.
The trick to make this work is to add a second parameter to the function signature. A call to flatten(head, rest) will flatten head and concatenate rest to the end of it. That allows our recursive definition:
head->next = flatten(head->child, flatten(head->next, rest));
image
(The first line of code is a simple base-case. The third and fourth lines are just pointer-cleanup.)
What we're passing to rest is an already flattened head->next, in order to concatenate it to the end of a flattened head->child.