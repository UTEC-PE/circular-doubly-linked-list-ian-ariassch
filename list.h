#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* start;
    int nodes;
public:

    List(){
        start = NULL;
        nodes = 0;
    };

    T front(){
        if(nodes == 0)throw "Error";
        return start-> data;
    };
    T back(){
        return start->prev->data;
    };
    void print(){
        Node<T> *temp= start;
        for(int contador = 0; contador < nodes; contador++){
            cout<<temp->data <<" ";
            temp = temp->next;
        }
        delete temp;
    };
    void push_front(T value){
        Node<T> *temp=new Node<T>;
        temp->data=value;
        if (nodes == 0){
            start = new Node<T>;
            start->data = temp->data;
            start->next = start;
            start->prev = start;
        }
        else{
            temp->next = start;
            temp->prev=start->prev;
            start->prev->next=temp;
            start->prev = temp;
            start= temp;}
        nodes++;
    };
    void push_back(T value){
        Node<T> *temp=new Node<T>;
        temp->data = value;
        if (nodes == 0){
            start = temp;
            start -> next = start;
            start -> prev = start;
        }
        else{
            temp->prev = start->prev;
            temp->next = start;

            start->prev->next = temp;
            start->prev = temp;}
        nodes++;
    };
    void pop_front(){
        auto *temp=start;
        if(nodes == 0)throw "Error";
        if(nodes == 1){

            start = NULL;
            delete temp;

        }
        start->prev->next=start->next;
        start = start->next;
        start->prev = temp->prev;
        delete temp;
        nodes--;


    };
    void pop_back(){
        if (nodes == 0)throw "Error";
        if (nodes == 1){
            start = NULL;
        }
        else{
            auto *temp=start->prev;
            start->prev= temp->prev;
            temp->prev->next=start;
            delete temp;}
        nodes--;
    };
    T get(int position){
        auto *temp = start;
        if (nodes == 0)throw "Error";
        if (position >= nodes) throw "Error";
        for(int contador = 0; contador<nodes; contador++){
            if(contador == position){
                return temp->data;
            }
            temp = temp->next;
        }
    };
    bool empty(){
        return nodes == 0;
    }
    int size(){
        return nodes;
    }
    void clear(){
        if(nodes == 0)cout<<"Lista ya está vacia";
        auto *temp=start->next;
        while(temp != start){
            auto *borrar = temp;
            temp=temp->next;
            delete borrar;
        }
        start = NULL;
        delete temp;
        nodes = 0;
    };
    Iterator<T> begin(){return Iterator<T>(start);}
    Iterator<T> end(){return Iterator<T>(start->prev);}

    ~List(){};
};

#endif