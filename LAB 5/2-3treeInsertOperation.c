void insert(node *candidate, t *key) 
	{if(candidate == nullptr) {
		root = new node(key);
		return;
	}
	if(candidate->isleaf()) {
		candidate->store(key);
	}else {
		if(*candidate->firstkey > *key) {
			insert(candidate->less, key);
		}else if(*candidate->firstkey <= *key && candidate->is2node()) {
			insert(candidate->btwn, key); 
		}else {
			if(*candidate->secondkey > *key) {
				insert(candidate->btwn, key); 
			}else {
				insert(candidate->great, key); 
			}
		}
	}
	split(candidate); 	
}
