void insert(lnode*& curr, int val) {
struct lnode* val = (struct lnode*) malloc(sizeof(struct lnode)); 
    if (curr == NULL)
        curr = new lnode(val, NULL);
    else if (lnode->val > val)
        curr = new lnode(val, curr->next);
    else {
        curr = curr->next;
        insert(curr, val);
    }
}
