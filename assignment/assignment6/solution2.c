#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CAP 10000
#define NAME_LEN 101

struct info {
    int id;
    int severity;
    char name[NAME_LEN];
};

struct heap {
    struct info *data;
    int capacity;
    int size;
};

void swap_info(struct info *a, struct info *b) {
    struct info tmp = *a;
    *a = *b;
    *b = tmp;
}

struct heap *heap_init(int capacity) {
    struct heap *hp = (struct heap *)malloc(sizeof(struct heap));
    hp->data = (struct info *)malloc(sizeof(struct info) * capacity);
    hp->capacity = capacity;
    hp->size = 0;
    return hp;
}

int find_index_by_id(struct heap *hp, int id) {
    for (int i = 0; i < hp->size; ++i)
        if (hp->data[i].id == id) return i;
    return -1;
}

int severity_exists(struct heap *hp, int severity) {
    for (int i = 0; i < hp->size; ++i)
        if (hp->data[i].severity == severity) return 1;
    return 0;
}

void heapify_up(struct heap *hp, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (hp->data[parent].severity > hp->data[idx].severity) {
            swap_info(&hp->data[parent], &hp->data[idx]);
            idx = parent;
        } else break;
    }
}

void heapify_down(struct heap *hp, int idx) {
    while (1) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < hp->size && hp->data[left].severity < hp->data[smallest].severity)
            smallest = left;
        if (right < hp->size && hp->data[right].severity < hp->data[smallest].severity)
            smallest = right;
        if (smallest != idx) {
            swap_info(&hp->data[smallest], &hp->data[idx]);
            idx = smallest;
        } else break;
    }
}

void print_level_order_ids(struct heap *hp) {
    int front = 0, rear = 0;
    int queue[hp->capacity];
    queue[rear++] = 0;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", hp->data[node].id);

        int left = 2 * node + 1;
        int right = 2 * node + 2;

        if (left < hp->size) queue[rear++] = left;
        if (right < hp->size) queue[rear++] = right;
    }
    printf("\n");
}

void admit_patient(struct heap *hp, int id, int severity, char name[],int print_order) {
    if (hp->size == hp->capacity) {
        return;
    }
    hp->data[hp->size].id = id;
    hp->data[hp->size].severity = severity;
    strcpy(hp->data[hp->size].name, name);
    heapify_up(hp, hp->size);
    hp->size++;
    if(print_order) print_level_order_ids(hp);
}

struct info extract_min(struct heap *hp) {
    struct info ret;
    if (hp->size <= 0) {
        ret.id = -1;
        ret.severity = INT_MAX;
        ret.name[0] = '\0';
        return ret;
    }
    ret = hp->data[0];
    hp->data[0] = hp->data[hp->size - 1];
    hp->size--;
    if (hp->size > 0) heapify_down(hp, 0);
    return ret;
}

int update_severity(struct heap *hp, int id, int new_sev) {
    int idx = find_index_by_id(hp, id);
    if (idx == -1) return -1;

    
    int old = hp->data[idx].severity;
    hp->data[idx].severity = new_sev;
    if (new_sev < old) heapify_up(hp, idx);
    else if (new_sev > old) heapify_down(hp, idx);
    return 0;
}

int query_patient(struct heap *hp, int id, struct info *out) {
    int idx = find_index_by_id(hp, id);
    if (idx == -1) return -1;
    if (out) *out = hp->data[idx];
    return idx;
}


void find_most_severe(struct heap *hp, int k) {
    if (hp->size < k)
    {
        printf("-1\n");
        return;
    }

    struct info temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = hp->data[0];
        extract_min(hp);
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d %s %d\n",temp[i].id,temp[i].name,temp[i].severity);
    }
    
    for (int i = 0; i < k; i++)
    {
        admit_patient(hp, temp[i].id,temp[i].severity,temp[i].name,0);
    }
}

int main() {
    struct heap *hp = heap_init(MAX_CAP);
    char mode;
    while (scanf(" %c", &mode) == 1) {
        if (mode == 'a') {
            int id, severity;
            char name[NAME_LEN];
            scanf("%d %d %[^\n]", &id, &severity, name);
                
            if (find_index_by_id(hp, id) != -1) {
                continue;
            }
            if (severity_exists(hp, severity)) {
                continue;
            }
            admit_patient(hp, id, severity, name,1);
        }
        else if (mode == 'b') {
            if (hp->size == 0) {
                printf("-1\n");
            } else {
                struct info p = extract_min(hp);
                printf("%d %s\n", p.id, p.name);
            }
        }
        else if (mode == 'c') {
            int id, new_sev;
            scanf("%d %d", &id, &new_sev);
            int res = update_severity(hp, id, new_sev);
            if (res == -1) {
                printf("-1\n");
            } else {
                print_level_order_ids(hp);
            }
        }
        else if (mode == 'd') {
            int id;
           scanf("%d", &id);
            struct info out;
            if (query_patient(hp, id, &out) == -1) {
                printf("-1\n");
            } else {
                printf("%s %d\n", out.name, out.severity);
            }
        }
        else if (mode == 'e') {
            find_most_severe(hp,3);

            
        }
        else if (mode == 'f') {
            break;
        }
        
    }

    free(hp->data);
    free(hp);
    return 0;
}
