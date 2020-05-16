
#include <IndexPointsAluno.h>

/// returns the number of elements in the index
long IndexPointsAluno::size() {
	//return _map.size();
	return contador;
}

/// adds new element to the index. 
void IndexPointsAluno::add (float key, long idx) {
	//_map.insert(std::make_pair(key,idx));

	noh* raiz_anterior = raiz;
	noh* raiz_nova = nil;
	noh* novo_noh = new noh(idx, key, nil, nil, nil);

	while (raiz_anterior != nil){
		raiz_nova = raiz_anterior;

		if (novo_noh->key < raiz_anterior->key)
			raiz_anterior = raiz_anterior->esquerda;
		else
			raiz_anterior = raiz_anterior->direita;
	}

	novo_noh->pai = raiz_nova;

	if (raiz_nova == nil)
		raiz = novo_noh;
	else if (novo_noh->key < novo_noh->pai->key)
		raiz_nova->esquerda = novo_noh;
	else
		raiz_nova->direita = novo_noh;

	novo_noh->esquerda = nil;
	novo_noh->direita = nil;
	novo_noh->vermelho = true;

	RB_insert_fixup(novo_noh);

	contador++;
}

void IndexPointsAluno::find(std::vector<long> &res, float first, float last) {
    
  // it is float, so it is not possible to compare with ==
  // the only thing that makes sense is too look for a range from
  // a min value to a max value. 
  // stl::multimap implements this using iterators 
  // you do not need to use iterators, but you need to fill the answer in O(k + logn)
  // where k is the number of elements in the range from first to last
  // in other words: NAO VALE FAZER INORDER COMPLETO E SELECIONAR O RANGE
  // PRECISA UM INORDER ESPERTO QUE ACHA O FIRST em O(log n) E CONTINUA ATE O LAST
  //auto itlow = _map.lower_bound (first);  // itlow points to first
  //auto itup = _map.upper_bound (last);   // itup points to next after last (not to last)

  // print range [itlow,itup), which is the same as [itlow, last] or [first, last]
  //for (auto it=itlow; it!=itup; ++it)
    //std::cout << (*it).first << " => " << (*it).second << '\n';
    //res.push_back((*it).second);

	buscar(res, first, last, raiz);

    
}//find

void IndexPointsAluno::RB_insert_fixup(noh* novo_noh){

	noh* raiz_nova = nil;

	while (novo_noh->pai->vermelho == true){

		if (novo_noh->pai == novo_noh->pai->pai->esquerda){

			noh* raiz_nova = novo_noh->pai->pai->direita;

			if (raiz_nova->vermelho == true){
				novo_noh->pai->vermelho = false;
				raiz_nova->vermelho = false;
				novo_noh->pai->pai->vermelho = true;
				novo_noh = novo_noh->pai->pai;
			}

			else{
				if (novo_noh == novo_noh->pai->direita){
					novo_noh = novo_noh->pai;
					rotacao_esquerda (novo_noh);
				}

				novo_noh->pai->vermelho = false;
				novo_noh->pai->pai->vermelho = true;
				rotacao_direita (novo_noh->pai->pai);
			}
		}

		else if (novo_noh->pai == novo_noh->pai->pai->direita){
			
			raiz_nova = novo_noh->pai->pai->esquerda;

			if (raiz_nova->vermelho == true){
				novo_noh->pai->vermelho = false;
				raiz_nova->vermelho = false;
				novo_noh->pai->pai->vermelho = true;
				novo_noh = novo_noh->pai->pai;
			}

			else{
				if (novo_noh == novo_noh->pai->esquerda){
					novo_noh = novo_noh->pai;
					rotacao_direita (novo_noh);
				}
			
				novo_noh->pai->vermelho = false;
				novo_noh->pai->pai->vermelho = true;
				rotacao_esquerda (novo_noh->pai->pai);
			}
		}
	}

	while(raiz->pai != nil)
		raiz = raiz->pai;


	raiz->vermelho = false;

}

void IndexPointsAluno::rotacao_direita(noh* raiz_anterior){

	noh* raiz_nova = raiz_anterior->esquerda;
	raiz_anterior->esquerda = raiz_nova->direita;

	if (raiz_nova->direita != nil){
		raiz_nova->direita->pai = raiz_anterior;
	}

	raiz_nova->pai = raiz_anterior->pai;

	if (raiz_anterior->pai == nil){
		raiz = raiz_nova;
	}
	else if (raiz_anterior == raiz_anterior->pai->direita){
		raiz_anterior->pai->direita = raiz_nova;
	}
	else{
		raiz_anterior->pai->esquerda = raiz_nova;
	}

	raiz_nova->direita = raiz_anterior;
	raiz_anterior->pai = raiz_nova;

}

void IndexPointsAluno::rotacao_esquerda(noh* raiz_anterior){
	
	noh* raiz_nova = raiz_anterior->direita;
	raiz_anterior->direita = raiz_nova->esquerda;

	if (raiz_nova->esquerda != nil){
		raiz_nova->esquerda->pai = raiz_anterior;
	}

	raiz_nova->pai = raiz_anterior->pai;

	if (raiz_anterior->pai == nil){
		raiz = raiz_nova;
	}
	else if (raiz_anterior == raiz_anterior->pai->esquerda){
		raiz_anterior->pai->esquerda = raiz_nova;
	}
	else{
		raiz_anterior->pai->direita = raiz_nova;
	}

	raiz_nova->esquerda = raiz_anterior;
	raiz_anterior->pai = raiz_nova;
}

void IndexPointsAluno::buscar(std::vector<long> &res, float first, float last, noh* raiz){
	
	if (raiz != nil){

		if (first <= raiz->key and last >= raiz->key){

			buscar(res, first, last, raiz->esquerda);
			res.push_back(raiz->idx);
			buscar(res, first, last, raiz->direita);
		}

		else{
			
			if (first > raiz->key)
				buscar(res, first, last, raiz->direita);

			else if (last < raiz->key)
				buscar(res, first, last, raiz->esquerda);
		}
	}
}
