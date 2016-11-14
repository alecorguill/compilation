float WIDTH;
float HEIGHT;
float START_ZOOM;
float BAIL_OUT;
float ZOOM_FACTOR;

float zoom;

void my_setup()
{
  WIDTH = 640;
  HEIGHT = 480;
  START_ZOOM = (WIDTH * 0.25296875f);
  BAIL_OUT = 2.0;
  ZOOM_FACTOR = 1.4;
  // Définit la taille de la zone d'affichage
  createCanvas(WIDTH, HEIGHT);
  zoom = START_ZOOM;
}

void my_draw()
{
  int x,y,n;
  int maxiter = (WIDTH/2) * 0.049715909 * log10(zoom);
  float zr,zi,cr,ci;
  float centerr = -0.800671;
  float centeri = 0.158392;

  for  (y = 0; y < HEIGHT; y++)  {
    for (x = 0; x < WIDTH; x++) {
      float m=0;
      /* Get the complex poing on gauss space to be calculate */
      zr=cr=centerr + (x - (WIDTH/2))/zoom;
      zi=ci=centeri + (y - (HEIGHT/2))/zoom;
      /* Applies the actual mandelbrot formula on that point */
      for (n = 0; n <= maxiter && m < BAIL_OUT * BAIL_OUT; n ++) {
	float a=zr*zr-zi*zi+cr;
	float b=2*zr*zi+ci;
	zr=a;
	zi=b;
	m=a*a+b*b;
      }

      /* Paint the pixel calculated depending on the number
	 of iterations found */
      int color;
      if (n<maxiter)
	color=((float) n) / maxiter * 255;
      else color=0;

      //fill(color);
      stroke(color);
      point(x, y);
    }
  }

  zoom *= ZOOM_FACTOR;
}

