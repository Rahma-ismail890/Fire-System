
#ifndef RGB_LED_H_
#define RGB_LED_H_

extern u8 flag;
typedef struct
{
	u8 RED;
	u8 GREEN;
	u8 BLUE;
	}RGB_LIGHTS;


typedef enum
{ 
	black=0,
	white,
	red,
	green,
	blue,
	yellow,
	purple,
	aqua,
	brown,
	bink,
	dark_green,
	dark_blue,
	dark_magenta,
	orange,
	total_lights
	}light_name;
	
	void RGB_light(light_name light);
	void showRoom(light_name light1,light_name light2);

#endif /* RGB_LED_H_ */