# define _CRT_SECURE_NO_WARNINGS
# define _CRT_NONSTDC_NO_DEPRECATE
# include <stdio.h>
# include <stdlib.h>
# define TRUE 1
# define FALSE 0


struct
node
{
    int
data;
struct
node * next;
} node;
struct
node * queue = NULL;
void
addq(int
data) {
    struct
node * ptr = NULL, *temp = NULL;
temp = (struct node *)
malloc(sizeof(struct
node));
temp->data = data;
temp->next = NULL;
if (queue)
{
for (ptr = queue; ptr->next; ptr = ptr->next);
ptr->next = temp;
}
else
queue = temp;
}
int
deleteq()
{
    struct
node * ptr = NULL;
int
data;
if (queue)
{
    ptr = queue;
data = queue->data;
queue = queue->next;
free(ptr);
return data;
}
return -1;
}


void
insert_node(struct
node ** root, int
v) {
struct
node * temp = NULL;
struct
node * temp2 = *root;
temp = (struct node *)
malloc(sizeof(struct
node));
temp->data = v;
temp->next = NULL;
if (*root == NULL)
    {
        temp->next = *root;
    *root = temp;
    }
    else if ((*root)->data > v)
        {
            temp->next = *root;
        *root = temp;
        }
        else
        {
        while (true)
            {
            if (temp2->next == NULL)
            {
                temp2->next = temp;
            break;
            }
            else if (temp2->next->data > v)
            {
            temp->next = temp2->next;
            temp2->next = temp;
            break;
        }
        else
        temp2 = temp2->next;
        }
        }
        }

        void
        insert_graph(struct
        node ** G, int
        vi, int
        vj) {
            insert_node( & (G[vi]), vj);
        insert_node( & (G[vj]), vi);
        }

        int
        degree(struct
        node * graph) {
            int
        count = 0;
        while (graph) {
        graph = graph->next;
        count++;
        }
        return count;
        }

        void
        DFS(struct
        node ** graph, int
        v, int * visited) {
        struct
        node * w;
        visited[v] = TRUE;
        printf("%d ", v);
        for (w = * (graph + v); w; w = w->next)
        if (!visited[w->data])
            DFS(graph, w->data, visited);
            }

            void
            BFS(struct
            node ** graph, int
            v, int * visited) {
            struct
            node * w;
            printf("%d ", v);
            visited[v] = TRUE;
            addq(v);
            while (queue)
                {
                    v = deleteq();
                for (w = graph[v]; w; w = w->next)
                if (!visited[w->data]) {
                printf("%d ", w->data);
                addq(w->data);
                visited[w->data] = TRUE;
                }
                }
            }

            int
            main()
            {

            struct
            node ** G = NULL;
            int * visited = NULL;
            int
            n, vi, vj, ntmp = 0, nnum = 0;
            int
            max_i, max_degree;
            scanf("%d %d %d", & n, & nnum, & ntmp);
            G = (struct node **)
            calloc(n + 1, sizeof(struct
            node *));
            for (int i = 0; i < nnum; i++)
                {
                    scanf("%d %d", & vi, & vj);
                insert_graph(G, vi, vj);
                }

                visited = (int *)
                calloc(n + 1, sizeof(int));
                for (int i = 0; i < n+1; i++)
                    visited[i] = FALSE;

                DFS(G, ntmp, visited);
                printf("\n");
                for (int i = 0; i < n+1; i++)
                    visited[i] = FALSE;

                BFS(G, ntmp, visited);

                }