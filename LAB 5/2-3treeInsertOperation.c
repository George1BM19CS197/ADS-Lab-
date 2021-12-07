void insert(node *candidate, t *key) { //Here key is the element to be inserted in the candidate
if(candidate == nullptr) {
root = new node(key);
return;
}
if(candidate-&gt;isleaf()) {
candidate-&gt;store(key);
}else {
if(*candidate-&gt;firstkey &gt; *key) {
insert(candidate-&gt;less, key); //Insert to left subtree.
}else if(*candidate-&gt;firstkey &lt;= *key &amp;&amp; candidate-&gt;is2node()) {
insert(candidate-&gt;btwn, key); //Insert to mid subtree.
}else {
if(*candidate-&gt;secondkey &gt; *key) {
insert(candidate-&gt;btwn, key); //Insert to mid subtree.
}else {
insert(candidate-&gt;great, key); //Insert to right subtree.
}
}
}
split(candidate); //This function is to balance the tree incase of an overflow.
}
