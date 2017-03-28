
//precision mediump float;	// Precisión media

uniform sampler2D u_TextureSampler;

varying vec4 v_Color;		    // in: color del vertex shader
varying vec2 v_TextureCoord;    // in: coordenadas de textura

void main()
{
  gl_FragColor = v_Color * texture2D(u_TextureSampler, v_TextureCoord);
}
