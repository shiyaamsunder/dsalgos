#include <stdio.h>
int heap[40];
int size = -1;

int parent(int i)
{
  return (i - 1) / 2;
}
int left_child(int i)
{
  return i + 1;
}
int right_child(int i)
{
  return i + 2;
}
int get_Max()
{
  return heap[0];
}
int get_Min()
{
  return heap[size];
}
void moveUp(int i)
{
  while (i > 0)
  {
    // swapping parent node with a child node
    if (heap[parent(i)] < heap[i])
    {

      int temp;
      temp = heap[parent(i)];
      heap[parent(i)] = heap[i];
      heap[i] = temp;
    }
    // updating the value of i to i/2
    i = i / 2;
  }
}

void moveDown(int k)
{
  int index = k;

  int left = left_child(k);

  if (left <= size && heap[left] > heap[index])
  {
    index = left;
  }

  int right = right_child(k);

  if (right <= size && heap[right] > heap[index])
  {
    index = right;
  }

  if (k != index)
  {
    int temp;
    temp = heap[index];
    heap[index] = heap[k];
    heap[k] = temp;
    moveDown(index);
  }
}

void removeMax()
{
  int r = heap[0];
  heap[0] = heap[size];
  size = size - 1;
  moveDown(0);
}
// inserting the element in a priority queue
void insert(int p)
{
  size = size + 1;
  heap[size] = p;

  // move Up to maintain heap property
  moveUp(size);
}

// Removing the element from the priority queue at a given index i.
void delete(int i)
{
  heap[i] = heap[0] + 1;

  // move the node stored at ith location is shifted to the root node
  moveUp(i);

  // Removing the node having maximum priority
  removeMax();
}

void print(){
  for (int i = 0; i <= size; i++)
  {
    printf("%d ", heap[i]);
  }
  printf("\n");
}
int main()
{
  // Inserting the elements in a priority queue

  // insert(20);
  // insert(19);
  // insert(21);
  // insert(18);
  // insert(12);
  // insert(17);
  // insert(15);
  // insert(16);
  // insert(14);

  printf("Priority Queue\n");
  printf("--------------\n");

  int c;
  do{
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Highest Priority\n");
      printf("4. Lowest Priority\n");
      printf("5. Print\n");

      printf("Enter choice: ");
      scanf("%d", &c);

      switch (c)
      {
      case 1:
        {
          int ele;
          printf("Enter element: ");
          scanf("%d", &ele);
          insert(ele);
          printf("Inserted\n");
        }
        break;
      case 2:
      {
        int pos;
        printf("Enter position: ");
        scanf("%d", &pos);
        delete(pos-1);
        printf("Deleted\n");
      }
        break;

      case 3:
        printf("Element with highest priority: %d\n", get_Max());
        break;

      case 4:
        printf("Element with lowest priority: %d\n", get_Min());
        break;

      case 5:
        print();
        break;
      default:
        break;
      }
  }
  while(c!=0);


}