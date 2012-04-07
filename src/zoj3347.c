#include <stdio.h>

typedef struct
{
    int w, h;
    int pixels[256][256];
} Image;

typedef struct
{
    int x1, y1, x2, y2;
    int code;
} ImageOp;

int main()
{
    Image image;
    ImageOp ops[100000];

    int n;
    int i, j;
    int x, y, invert, offset;

    while(scanf("%d %d", &image.w, &image.h) != EOF)
    {
        for(i = 0; i < image.h; i++)
            for(j = 0; j < image.w; j++)
                scanf("%d", &image.pixels[i][j]);
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d %d %d %d %d", &ops[i].x1, &ops[i].y1, &ops[i].x2, &ops[i].y2, &ops[i].code);
        scanf("%d %d", &x, &y);

        invert = 1;
        offset = 0;
        for(i = n - 1; i >= 0; i--)
        {
            if(x >= ops[i].x1 && x <= ops[i].x2 && y >= ops[i].y1 && y <= ops[i].y2)
            {
                switch(ops[i].code)
                {
                    case 1:
                        invert *= -1;
                        offset *= -1;
                        break;
                    case 2:
                        offset += 1;
                        break;
                    case 3:
                        offset -= 1;
                        break;
                    case 4:
                        x = ops[i].x1 + ops[i].x2 - x;
                        break;
                    case 5:
                        y = ops[i].y1 + ops[i].y2 - y;
                        break;
                }
            }
        }
        printf("%d\n", invert * (image.pixels[y][x] + offset));
    }

    return 0;
}
