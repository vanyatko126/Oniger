
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;    // начало отрезка
    Point b;    // конец отрезка
    float len;  // длина отрезка
} Line;

float distance(Line t);   // расстояние между точками
void scanLine(Line * t);
void printLine(Line t);
void rotRLine(Line * t);

int main() {
    Line t;

    scanLine(&t);
    rotRLine(&t);
    printLine(t);

    return 0;
}

void scanLine(Line * t)
{
    scanf("%d %d %d %d", &t->a.x, &t->a.y, &t->b.x, &t->b.y);
}
void rotRLine(Line * t)
{
    int x1 = t->a.x;
    int y1 = t->a.y;
    t->a.x = t->a.y;
    t->a.y = (-1) * x1;
    int x2 = t->b.x;
    int y2 = t->b.y;
    t->b.x = y2;
    t->b.y = (-1) * x2;
}

void printLine(Line t)
{
    float dist = distance(t);
    printf("%d %d %d %d %.3f", t.a.x, t.a.y, t.b.x, t.b.y, dist);
}
float distance(Line t)
{
    float d =  sqrt(((t.b.x - t.a.x) * (t.b.x - t.a.x)) + ((t.b.y - t.a.y) * (t.b.y - t.a.y)));
    return d;
}
