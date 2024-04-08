import math

def OrdenacaoRaizQuadrada (lista):
    # Dividir em listas de tamanho raiz de n
    tam_lista = len(lista)
    n = int(math.sqrt(tam_lista))

    sub_listas = []

    tamanho_sublista = int(tam_lista / n)

    #sub_listas = lista com os vetores como elementos
    for i in range(0, tam_lista, tamanho_sublista):
        sub_listas.append(lista[i:i + tamanho_sublista])

    lista_aux = []
    lista_resultado = []

    #faz o sort dos vetores da lista
    for sub_lista_elemento in sub_listas:
        sub_lista_elemento.sort(reverse=True)
        lista_aux.append(sub_lista_elemento[0])

    #faz o processo de retirar e colocar no resultado o maior valor
    while sub_listas:
        
        a = max(lista_aux)
        lista_resultado.insert(0,a)
        
        for sub_lista_elemento in sub_listas:
            if sub_lista_elemento:
                if sub_lista_elemento[0] == a:
                    sub_lista_elemento.pop(0)
                    if sub_lista_elemento and sub_lista_elemento[0] != None:
                        indice_a = lista_aux.index(a)
                        lista_aux.pop(indice_a)
                        lista_aux.append(sub_lista_elemento[0])
                        break;
                    else:
                        lista_aux.remove(a)
            if not sub_lista_elemento:
                sub_listas.remove(sub_lista_elemento)
    return lista_resultado


            
    

       
            




