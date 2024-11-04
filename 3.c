Color getColor()
{
    Color p = {0,0,0};
    
    scanf("%d %d %d", &p.red, &p.green, &p.blue);
    
    return p;  
}

unsigned long long convertToHTML(Color z)
{
    int a1, a2, b1, b2, c1, c2;
    
    a2 = z.red % 16;
    a1 = (z.red / 16) % 16;
    
    b2 = z.green % 16;
    b1 = (z.green / 16) % 16;
    
    c2 = z.blue % 16;
    c1 = (z.blue / 16) % 16;
    
    int x = 0;
    
    x += a1*16*16*16*16*16;
    x += a2*16*16*16*16;
    
    x += b1*16*16*16;
    x += b2*16*16;
    
    x += c1*16;
    x += c2;
    return x;
}

