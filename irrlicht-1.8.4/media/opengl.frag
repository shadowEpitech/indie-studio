<<<<<<< HEAD

uniform sampler2D myTexture;

void main (void)
{
    vec4 col = texture2D(myTexture, vec2(gl_TexCoord[0]));
    col *= gl_Color;
    gl_FragColor = col * 4.0;
}
=======

uniform sampler2D myTexture;

void main (void)
{
    vec4 col = texture2D(myTexture, vec2(gl_TexCoord[0]));
    col *= gl_Color;
    gl_FragColor = col * 4.0;
}
>>>>>>> b1408e684c5c46477537278bcd13e4812bb4e72a
