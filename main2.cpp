 #include <irrlicht.h>
 using namespace irr;
 using namespace irr::core;
 int main(){
      IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2du(1366, 768), 32, false, false, true);

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* scenemgr = device->getSceneManager();

    device->setWindowCaption(L"Hello World!");
    scenemgr ->addSkyBoxSceneNode(driver->getTexture("res/skytop.jpg"), 
                                 driver->getTexture("res/skybottom.jpg"),
                                 driver->getTexture("res/sky3.jpg"),
                                 driver->getTexture("res/sky1.jpg"),
                                 driver->getTexture("res/sky0.jpg"),
                                 driver->getTexture("res/sky2.jpg")
                                 );
    auto t = scenemgr->addTerrainSceneNode("res/heightmap.png"); 
    t->setScale(vector3df(1.f, .1f, 1.f));
    auto move = t->getTerrainCenter();
    move.Y += 10.f;
    t->setPosition(-move);
    t->setMaterialFlag(irr::video::EMF_FOG_ENABLE, false);
    t->setMaterialTexture(0,driver->getTexture("res/detailmap.png"));    
    driver->setFog(video::SColor(0, 99, 122, 193), irr::video::EFT_FOG_EXP, 100.f, 300.f);                        
    scenemgr->addCameraSceneNodeFPS();
    scene::ILightSceneNode *sun = scenemgr->addLightSceneNode();
    sun->setLightType(irr::video::ELT_DIRECTIONAL);
    sun->setRotation(vector3df(45.f, 0.f, 0.f));

    while(device->run() && driver)
    {
        
        driver->beginScene(true, true, irr::video::SColor(255, 128, 128, 128));
        scenemgr->drawAll();
        
        driver->endScene();
    }

    driver->drop();

     return 0;
 }