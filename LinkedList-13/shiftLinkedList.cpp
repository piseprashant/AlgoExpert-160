
LinkedList *LinkListshift(LinkedList *head, int k) {
  
	// We basically nead 4 nodes to solve this
	//we got the headNode
	
	int countNoNodes = 1;
	// we got the tailNode
	LinkedList *tailNode = head;
	while (tailNode->next != nullptr)
	{
		tailNode = tailNode->next;
		countNoNodes++;
	}
	
	int offset = abs(k) % countNoNodes;
	
	if (offset == 0) return head;
	int newTailPos = k>0 ? (countNoNodes - offset) : offset;
	
	LinkedList *newTail = head;
	
	for (int index = 1; index < newTailPos; index++)
	{
		newTail = newTail->next;
	}
	
	LinkedList *newHead = newTail->next;
	newTail->next = nullptr;
	tailNode->next = head;
	return newHead;
}

