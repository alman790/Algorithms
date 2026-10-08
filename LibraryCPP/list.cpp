#include "list.h"

struct ListItem
{
    ListItem *prev;
    Data value;
    ListItem *next;

    ListItem(Data val) : prev(nullptr), value(val), next(nullptr) {}
    ~ListItem() = default;
};

struct List
{
    ListItem *head = nullptr;
    ListItem *tail = nullptr;

    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        ListItem *curr = head;
        while (curr != nullptr) {
            ListItem *next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        tail = nullptr;
    };
};

List *list_create()
{
    return new List;
}

void list_delete(List *list)
{
    delete list;
}

ListItem *list_first(List *list)
{
    return list->head;
}

ListItem *list_last(List *list)
{
    return list->tail;
}

Data list_item_data(const ListItem *item)
{
    return item->value;
}

ListItem *list_item_next(ListItem *item)
{
    return item->next;
}

ListItem *list_item_prev(ListItem *item)
{
    return item->prev;
}

ListItem *list_insert(List *list, Data data)
{
    ListItem *item = new ListItem(data);
    if (list->head == nullptr) {
        list->head = item;
        list->tail = item;
    } else {
        ListItem *temp = list->head;

        list->head = item;
        item->next = temp;
        temp->prev = item;
    }

    return item;
}

ListItem *list_insert_after(List *list, ListItem *item, Data data)
{
    ListItem *new_item = new ListItem(data);
    bool flaged = false;

    if (list->head == list->tail && list->head == nullptr) {
        list->head = new_item;
        list->tail = new_item;
        flaged = true;
    }

    if (!flaged && item == nullptr) {
        ListItem *temp = list->head;

        list->head = new_item;
        new_item->next = temp;
        temp->prev = new_item;

        flaged = true;
    }

    if (!flaged) {
        if (item == list->tail) {
            ListItem *temp = list->tail;
            list->tail = new_item;
            new_item->prev = temp;
            temp->next = new_item;
        } else {
            new_item->next = list_item_next(item);
            new_item->prev = item;
            item->next = new_item;
            ListItem *temp = list_item_next(new_item);
            temp->prev = new_item;
        }
    }

    return new_item;
}

ListItem *list_erase_first(List *list)
{
    if (list->head == nullptr) return nullptr;

    if (list->head == list->tail) {
        ListItem *temp = list->head;

        list->head = nullptr;
        list->tail = nullptr;

        delete temp;
        return nullptr;
    }

    ListItem *temp = list->head;
    list->head = list->head->next;
    list->head->prev = nullptr;
    delete temp;

    return list->head;
}

ListItem *list_erase_next(List *list, ListItem *item)
{
    if (item == nullptr) return list_erase_first(list);

    if (list->head == nullptr || item->next == nullptr ) {
        return nullptr;
    }

    ListItem *next = list_item_next(item);
    ListItem *temp = next;
    next = list_item_next(next);
    item->next = next;

    if (next != nullptr) {
        next->prev = item;
    } else {
        list->tail = item;
    }

    delete temp;

    return next;
}
