#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	var_textures=1;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

	switch(key)
	{
	case 'a':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->toggleSomething();
			break;
		}
	case 'j':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->robot->rotateRight();
			break;
		}
	case 'l':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->robot->rotateLeft();
			break;
		}
	case 'i':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->robot->moveForward();
			break;
		}

	case 'k':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->robot->moveBackward();
			break;
		}

	}
}

void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Lights", 1);
	addCheckboxToPanel(varPanel, "Light 0", &(((LightingScene*) scene)->enable_light0), LIGHT0);
	addCheckboxToPanel(varPanel, "Light 1", &(((LightingScene*) scene)->enable_light1), LIGHT1);
	addCheckboxToPanel(varPanel, "Light 2", &(((LightingScene*) scene)->enable_light2), LIGHT2);
	addCheckboxToPanel(varPanel, "Light 3", &(((LightingScene*) scene)->enable_light3), LIGHT3);


	glui_window->add_column(false);
	GLUI_Panel *texture_pan = addPanel("Texture", 1);
	GLUI_Listbox *textures;
	textures = addListboxToPanel(texture_pan, "Texture", &var_textures, ROBOT_TEXTURE);
	textures->add_item(1, "Default");
	textures->add_item(2, "Carbon");
	textures->add_item(3, "Pyramid");
	textures->set_int_val(1);

	glui_window->add_column(false);
	GLUI_Panel *radio_pan = addPanel("Show mode", 1);
	GLUI_RadioGroup *radio;
	radio = addRadioGroupToPanel (radio_pan, 0, ROBOT_WIREFRAME);
	addRadioButtonToGroup(radio, "Texture");
	addRadioButtonToGroup(radio, "Wireframe");
	radio->set_selected(0);


	glui_window->add_column(false);
	GLUI_Panel * clock_pan = addPanel("Clock Control", 1);
	addButtonToPanel(clock_pan, "Stop/Start", CLOCK_UPDATE);
	

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	//printf ("GUI control id: %d\n  ",ctrl->user_id);
	//string robot_texture;
	switch (ctrl->user_id)
	{
	case CLOCK_UPDATE:
		((LightingScene*) scene)->clock->updateStopped();
		break;
	case LIGHT0:
		((LightingScene*) scene)->changeLight(LIGHT0);
		break;
	case LIGHT1:
		((LightingScene*) scene)->changeLight(LIGHT1);
		break;
	case LIGHT2:
		((LightingScene*) scene)->changeLight(LIGHT2);
		break;
	case LIGHT3:
		((LightingScene*) scene)->changeLight(LIGHT3);
		break;
	case ROBOT_WIREFRAME:
		((LightingScene*) scene)->robot->changeWireframe();
		break;
	case ROBOT_TEXTURE:
		((LightingScene*) scene)->robot->switchTexture(var_textures);
	//	std::cout<<"var_textures: "<<var_textures<<endl;
		break;
	};


}