//
// Created by arthu on 20/06/2018.
//

#include <cstdlib>
#include <ctime>
#include <Bomb.hpp>
#include "Window.hpp"
#include "Map.hpp"
#include "Game.hpp"
#include "Time.hpp"
#include "Player.hpp"

Game::Game(Window *window) : m_window(window)
{}

Game::~Game()
{}

bool	Game::initPlayer()
{
    m_window->getM_device()->setWindowCaption(L"Game mode");
    m_window->getM_gui()->addImage(m_window->getM_driver()->getTexture
				       (Window::getPath("assets/img/back"
			     ".jpeg")),
                    irr::core::position2d<irr::s32>(0,0));
    irr::gui::IGUIButton *solo = m_window->getM_gui()->addButton(
        irr::core::rect<irr::s32>(120, 90, 900, 490), nullptr,
            m_window->BUTTON_SOLO);
    irr::video::ITexture     *textuStart = m_window->getM_driver()
	->getTexture(Window::getPath("assets/img/solo2.png"));
    solo->setUseAlphaChannel(true);
    solo->setDrawBorder(false);
    solo->setImage(textuStart);

    irr::gui::IGUIButton	*multi = m_window
	->getM_gui()->addButton(irr::core::rect<irr::s32>(650, 70, 1600, 490),
                                                      nullptr,
                                                      m_window->BUTTON_MULTI);
    textuStart = m_window->getM_driver()->getTexture(Window::getPath
	("assets/img/multi2.png"));
    multi->setUseAlphaChannel(true);
    multi->setDrawBorder(false);
    multi->setImage(textuStart);

    irr::gui::IGUIButton	*back = m_window->getM_gui()
	->addButton(irr::core::rect<irr::s32>(600, 455, 1000, 800),
                                                     nullptr,
                                                     m_window->BUTTON_BACK);
    textuStart = m_window->getM_driver()->getTexture(Window::getPath
	("assets/img/Back3.png"));
    back->setUseAlphaChannel(true);
    back->setDrawBorder(false);
    back->setImage(textuStart);
    while (m_window->getM_device()->run() && m_window->getM_driver()) {
        if (m_window->getM_device()->isWindowActive()) {
            m_window->getM_driver()->beginScene(
                    true,
                    true,
                    irr::video::SColor(0, 0, 191, 255));
            m_window->getM_gui()->drawAll();
            m_window->getM_driver()->endScene();
            m_window->getM_device()->setEventReceiver(m_window);
        }
    }
    return true;
}

bool	Game::startGame()
{
	static std::vector<std::string>	refreshmap = Map::get_map_in_file
		(Window::getPath("assets/map/map").c_str());
    MyEventReceiver lreceiver;
    m_window->getM_device()->setEventReceiver(&lreceiver);
    m_window->getM_musicDevice().setMusic(
        Window::getPath("assets/music/BGM.ogg").c_str());
    m_window->getM_sceneManager()->clear();
    if (!m_window->getM_device())
        return false;
    m_window->getM_device()->setResizable(false);
    m_window->getM_device()->setWindowCaption(L"Bomberman");
    m_window->getM_device()->getFileSystem()
            ->addFileArchive(
                m_window->getPath("irrlicht-1.8.4/media/map-20kdm2.pk3"));
    	printMap(refreshmap);
    auto	*character1 = (new Player(m_window, 1, refreshmap))->getM_character2();
    auto	*character2 = (new Player(m_window, 2, refreshmap))->getM_character2();
    irr::scene::ICameraSceneNode *camera = m_window->getM_sceneManager()
        ->addCameraSceneNode(nullptr, irr::core::vector3df(-900, 1500, -800),
			     irr::core::vector3df(-900, -1500, 1200));
    m_window->getM_device()->getCursorControl()->setVisible(false);
    irr::scene::ISceneNode	*highlightedSceneNode = nullptr;
    irr::scene::ISceneCollisionManager	*collMan = m_window
        ->getM_sceneManager()->getSceneCollisionManager();
    irr::video::SMaterial	material;
    Time	then(m_window);
    std::string	filename = "darkskies";
    m_window->getM_sceneManager()->addSkyBoxSceneNode(
	    m_window->getM_driver()->getTexture(Window::getPath(
	        "assets/skybox/" + filename + "_up.tga")),
	    m_window->getM_driver()->getTexture(Window::getPath(
		"assets/skybox/" + filename + "_dn.tga")),
	    m_window->getM_driver()->getTexture(Window::getPath(
		"assets/skybox/" + filename + "_lf.tga")),
	    m_window->getM_driver()->getTexture(Window::getPath(
		"assets/skybox/" + filename + "_rt.tga")),
	    m_window->getM_driver()->getTexture(Window::getPath(
		"assets/skybox/" + filename + "_ft.tga")),
	    m_window->getM_driver()->getTexture(Window::getPath(
		"assets/skybox/" + filename + "_bk.tga")));
    m_window->getM_driver()->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
    auto	*bomb1 = new Bomb(0, 0, Entity::BOMB);
    auto	*bomb2 = new Bomb(0, 0, Entity::BOMB);
	    static int		check1 = 0;
	    static int		check2 = 0;
	    static int		p1havebomb = 0;
	    static int		p2havebomb = 0;
	    static float	lasttime1 = 0;
	    static float	lasttime2 = 0;
	    static float	bombtime1 = 0;
	    static float	bombtime2 = 0;
	    int			p1x = 0;
	    int			p1y = 0;
	    int			p2x = 0;
	    int			p2y = 0;
	    int			p1xb = 0;
	    int			p1yb = 0;
	    int			p2xb = 0;
	    int			p2yb = 0;
	    int			music = 0;
    	    irr::core::vector3df	lastpos1;
    	    irr::core::vector3df	lastpos2;
	    static float	timer1 = 0.0;
	    static float	timer2 = 0.0;
	while(m_window->getM_device()->run()) {
		const irr::u32 now = m_window->getM_device()->getTimer()
		    ->getTime();
		const irr::f32 frameDeltaTime = (irr::f32)
			(now - then.getM_then()) / 1000.f;
		then.setTime(now);
	    if (lreceiver.isKeyDown(irr::KEY_ESCAPE))
	    	m_window->createMenu(L"Bomberman menu", 0);
		irr::core::vector3df	nodePosition = mouvementCharacter1(lreceiver,
		   character1, m_movementSpeed, 0.330, &check1, &refreshmap,
		   refreshmap, now, &timer1);
		irr::core::vector3df nodePosition2 = mouvementCharacter2(lreceiver,
		     character2, m_movementSpeed, 0.330, &check2, &refreshmap,
	     	     refreshmap, now, &timer2);
	    if (lreceiver.isKeyDown(irr::KEY_KEY_E) && p1havebomb == 0
	    && now - bombtime1 > 3200) {
	    	bomb1->createBomb(character1, m_window);
		p1havebomb = 1;
		bombtime1 = now;
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '1') {
					p1x = i;
					p1y = j;
				}
			}
		}
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '2') {
					p2xb = i;
					p2yb = j;
				}
			}
		}
	    }
	    if (music == 1 && now - bombtime1 > 4800) {
		    music = 0;
        	    	m_window->createMenu(L"Bomberman menu", 1);
	    }
	    if (music == 2 && now - bombtime2 > 4800) {
		    music = 0;
        	    	m_window->createMenu(L"Bomberman menu", 1);
	    }
	    if (lreceiver.isKeyDown(irr::KEY_KEY_M) && p2havebomb == 0
	    && now - bombtime2 > 3200) {
	    	bomb2->createBomb(character2, m_window);
		p2havebomb = 1;
		bombtime2 = now;
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '2') {
					p2x = i;
					p2y = j;
				}
			}
		}
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '1') {
					p1xb = i;
					p1yb = j;
				}
			}
		}
 	    }
	    if (bomb1->exist() && now - bombtime1 > 3000) {
		music = 1;
	    	if (bomb1->checkDelete(m_window))
	    		bomb1 = new Bomb(0, 0, Entity::BOMB);
		m_window->getM_musicDevice().setMusic(
		        Window::getPath("assets/music/explosion.wav").c_str());
		if (refreshmap[p1x + 1][p1y] == ' ')
			refreshmap[p1x + 1][p1y] = 'x';
		if (refreshmap[p1x - 1][p1y] == ' ')
			refreshmap[p1x - 1][p1y] = 'x';
		if (refreshmap[p1x][p1y + 1] == ' ')
			refreshmap[p1x][p1y + 1] = 'x';
		if (refreshmap[p1x][p1y - 1] == ' ')
			refreshmap[p1x][p1y - 1] = 'x';
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '1') {
					if ((i == p1x && j == p1y)
					|| (i == p1x + 1 && j == p1y)
					|| (i == p1x - 1 && j == p1y)
					|| (i == p1x && j == p1y + 1)
					|| (i == p1x && j == p1y - 1)) {
						std::cout << "LOOSE" << std::endl;
						refreshmap = Map::get_map_in_file
							(Window::getPath("assets/map/map").c_str());
					    	m_window->createMenu(L"Bomberman menu", 0);
					}
				}
			}
		}
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '2') {
					if ((i == p2xb && j == p2yb)
					|| (i == p2xb + 1 && j == p2yb)
					|| (i == p2xb - 1 && j == p2yb)
					|| (i == p2xb && j == p2yb + 1)
					|| (i == p2xb && j == p2yb - 1)){
						std::cout << "WON" << std::endl;
						refreshmap = Map::get_map_in_file
							(Window::getPath("assets/map/map").c_str());
						m_window->createMenu(L"Bomberman menu", 0);
						}
				}
			}
		}
		p1havebomb = 0;
	    }
	    if (bomb2->exist() && now - bombtime2 > 3000) {
		music = 2;
	    	if (bomb2->checkDelete(m_window))
	    		bomb2 = new Bomb(0, 0, Entity::BOMB);
		m_window->getM_musicDevice().setMusic(
		        Window::getPath("assets/music/explosion.wav").c_str());
		if (refreshmap[p2x + 1][p2y] == ' ')
			refreshmap[p2x + 1][p2y] = 'x';
		if (refreshmap[p2x - 1][p2y] == ' ')
			refreshmap[p2x - 1][p2y] = 'x';
		if (refreshmap[p2x][p2y + 1] == ' ')
			refreshmap[p2x][p2y + 1] = 'x';
		if (refreshmap[p2x][p2y - 1] == ' ')
			refreshmap[p2x][p2y - 1] = 'x';
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '2') {
					if ((i == p2x && j == p2y)
					|| (i == p2x + 1 && j == p2y)
					|| (i == p2x - 1 && j == p2y)
					|| (i == p2x && j == p2y + 1)
					|| (i == p2x && j == p2y - 1)) {
						std::cout << "LOOSE" << std::endl;
						refreshmap = Map::get_map_in_file
							(Window::getPath("assets/map/map").c_str());
			    	    		m_window->createMenu(L"Bomberman menu", 0);
					}
				}
			}
		}
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (refreshmap[i][j] == '1') {
					if ((i == p1xb && j == p1yb)
					|| (i == p1xb + 1 && j == p1yb)
					|| (i == p1xb - 1 && j == p1yb)
					|| (i == p1xb && j == p1yb + 1)
					|| (i == p1xb && j == p1yb - 1)){
						std::cout << "WON" << std::endl;
						refreshmap = Map::get_map_in_file
							(Window::getPath("assets/map/map").c_str());
						m_window->createMenu(L"Bomberman menu", 0);
						}
				}
			}
		}
		p2havebomb = 0;
    	    	m_window->createMenu(L"Bomberman menu", 1);
	    }
	    if ((now - lasttime1 > 160) && check1) {
	    	lasttime1 = now;
		check1 = 0;
		character1->setPosition(nodePosition);
	    }
	    else if (check1) {
		check1 = 0;
	    }
	    if ((now - lasttime2 > 160) && check2) {
		lasttime2 = now;
		check2 = 0;
		character2->setPosition(nodePosition2);
	    }
	    else if (check2) {
		check2 = 0;
	    }
        m_window->getM_driver()->beginScene(
            true, true, irr::video::SColor(255, 113, 113, 133));
        irr::core::line3d<irr::f32>	ray;
        ray.start = camera->getPosition();
        ray.end = ray.start + (camera->getTarget() - ray.start)
				  .normalize() * 1000.0f;
        irr::core::vector3df	intersection;
        irr::core::triangle3df	hitTriangle;
        irr::scene::ISceneNode	*selectedSceneNode = collMan
	    ->getSceneNodeAndCollisionPointFromRay(
                ray, intersection, hitTriangle, 0);
        if (selectedSceneNode) {
            character1->setPosition(intersection);
            m_window->getM_driver()->setTransform(
                irr::video::ETS_WORLD, irr::core::matrix4());
            m_window->getM_driver()->setMaterial(material);
            m_window->getM_driver()->draw3DTriangle(
                hitTriangle, irr::video::SColor(0, 255, 0, 0));
            if ((selectedSceneNode->getID() & 1) == 1) {
                highlightedSceneNode = selectedSceneNode;

                highlightedSceneNode->setMaterialFlag(
                    irr::video::EMF_LIGHTING, false);
            }
        }
        m_window->getM_gui()->drawAll();
        m_window->getM_sceneManager()->drawAll();
        m_window->getM_driver()->endScene();
    }
    return true;
}

irr::core::vector3df	Game::mouvementCharacter2(
    const MyEventReceiver &lreceiver,
    irr::scene::IAnimatedMeshSceneNode *character2,
    const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime, int *check,
    std::vector<std::string> *refreshmap, std::vector<std::string> myrefreshmap
	, float now, float *timer) const
{
	irr::core::vector3df nodePosition2 = character2->getPosition();
	if (now - *timer < 160)
		return nodePosition2;
	int	j = 0;
	int	a = 0;
	int	b = 0;
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			if (myrefreshmap[i][j] == '2') {
				a = i;
				b = j;
			}
		}
	}
	if (*check == 1)
		return nodePosition2;
	if (lreceiver.isKeyDown(irr::KEY_UP)
	&& !lreceiver.isKeyDown(irr::KEY_DOWN)
	&& !lreceiver.isKeyDown(irr::KEY_RIGHT)
	&& !lreceiver.isKeyDown(irr::KEY_LEFT)) {

  *timer = now;
	    character2->setRotation(irr::core::vector3df(-90, 180, 0));
	    if (myrefreshmap[a + 1][b] != 'x')
    		return nodePosition2;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a + 1][b] = '2';
	    }
            nodePosition2.Z += MOVEMENT_SPEED * frameDeltaTime;
            character2->setAnimationSpeed(15);
            character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
            character2->setRotation(irr::core::vector3df(-90, 180, 0));
	    *check = 1;
        } else if (lreceiver.isKeyDown(irr::KEY_DOWN)
	&& !lreceiver.isKeyDown(irr::KEY_UP)
	&& !lreceiver.isKeyDown(irr::KEY_RIGHT)
	&& !lreceiver.isKeyDown(irr::KEY_LEFT)) {

  *timer = now;
	    character2->setRotation(irr::core::vector3df(-90, 0, 0));
	    if (myrefreshmap[a - 1][b] != 'x')
    		return nodePosition2;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a - 1][b] = '2';
	    }
            nodePosition2.Z -= MOVEMENT_SPEED * frameDeltaTime;
            character2->setAnimationSpeed(15);
            character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
	} else if (lreceiver.isKeyDown(irr::KEY_RIGHT)
	&& !lreceiver.isKeyDown(irr::KEY_DOWN)
	&& !lreceiver.isKeyDown(irr::KEY_UP)
	&& !lreceiver.isKeyDown(irr::KEY_LEFT)) {

  *timer = now;
	    character2->setRotation(irr::core::vector3df(-90, -90, 0));
	    if (myrefreshmap[a][b - 1] != 'x')
    		return nodePosition2;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a][b - 1] = '2';
	    }
            nodePosition2.X += MOVEMENT_SPEED * frameDeltaTime;
            character2->setAnimationSpeed(15);
            character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
        } else if (lreceiver.isKeyDown(irr::KEY_LEFT)
	&& !lreceiver.isKeyDown(irr::KEY_DOWN)
	&& !lreceiver.isKeyDown(irr::KEY_RIGHT)
	&& !lreceiver.isKeyDown(irr::KEY_UP)) {

  *timer = now;
	    character2->setRotation(irr::core::vector3df(-90, 90, 0));
	    if (myrefreshmap[a][b + 1] != 'x')
    		return nodePosition2;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a][b + 1] = '2';
	    }
            nodePosition2.X -= MOVEMENT_SPEED * frameDeltaTime;
            character2->setAnimationSpeed(15);
            character2->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
        }
	*refreshmap = myrefreshmap;
	return nodePosition2;
}

irr::core::vector3df	Game::mouvementCharacter1(
    const MyEventReceiver &lreceiver, irr::scene::IAnimatedMeshSceneNode *character1,
    const irr::f32 MOVEMENT_SPEED, const irr::f32 frameDeltaTime, int *check,
    std::vector<std::string> *refreshmap, std::vector<std::string> myrefreshmap
	, float now, float *timer) const
{
	irr::core::vector3df	character1Position = character1->getPosition();
	if (now - *timer < 160)
		return character1Position;
	int	j = 0;
	int	a = 0;
	int	b = 0;
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			if (myrefreshmap[i][j] == '1') {
				a = i;
				b = j;
			}
		}
	}
	if (*check == 1)
		return character1Position;
	if (lreceiver.isKeyDown(irr::KEY_KEY_Z)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_S)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_D)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_Q)) {

  *timer = now;
	    character1->setRotation(irr::core::vector3df(-90, 180, 0));
	    if (myrefreshmap[a + 1][b] != 'x')
    		return character1Position;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a + 1][b] = '1';
	    }
            character1Position.Z += MOVEMENT_SPEED * frameDeltaTime;
            character1->setAnimationSpeed(15);
            character1->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
    	} else if (lreceiver.isKeyDown(irr::KEY_KEY_S)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_Z)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_D)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_Q)) {

  *timer = now;
	    character1->setRotation(irr::core::vector3df(-90, 0, 0));
	    if (myrefreshmap[a - 1][b] != 'x')
    		return character1Position;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a - 1][b] = '1';
	    }
            character1Position.Z -= MOVEMENT_SPEED * frameDeltaTime;
            character1->setAnimationSpeed(15);
            character1->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
            } else if (lreceiver.isKeyDown(irr::KEY_KEY_D)
    	&& !lreceiver.isKeyDown(irr::KEY_KEY_S)
    	&& !lreceiver.isKeyDown(irr::KEY_KEY_Z)
    	&& !lreceiver.isKeyDown(irr::KEY_KEY_Q)) {

  *timer = now;
	    character1->setRotation(irr::core::vector3df(-90, -90, 0));
	    if (myrefreshmap[a][b - 1] != 'x')
    		return character1Position;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a][b - 1] = '1';
	    }
            character1Position.X += MOVEMENT_SPEED * frameDeltaTime;
            character1->setAnimationSpeed(15);
            character1->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
        } else if (lreceiver.isKeyDown(irr::KEY_KEY_Q)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_S)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_D)
	&& !lreceiver.isKeyDown(irr::KEY_KEY_Z)) {

  *timer = now;
	    character1->setRotation(irr::core::vector3df(-90, 90, 0));
	    if (myrefreshmap[a][b + 1] != 'x')
    		return character1Position;
	    else {
		    myrefreshmap[a][b] = 'x';
		    myrefreshmap[a][b + 1] = '1';
	    }
            character1Position.X -= MOVEMENT_SPEED * frameDeltaTime;
            character1->setAnimationSpeed(15);
            character1->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	    *check = 1;
        }
	*refreshmap = myrefreshmap;
	return character1Position;
}

void	Game::printMap(std::vector<std::string>	mymap) const
{
	int	j = 0;
	int	i = 0;
	auto	map = Map::MapGenerator(&i, &j);
	auto	img1 = m_window->getPath("assets/img/wall.jpeg");
	auto	img2 = m_window->getPath("assets/img/terrain.jpg");
	auto	img3 = m_window->getPath("assets/img/t351sml.jpg");
	for (int z = 0; z < i; z++) {
		for (int y = 0; y < j; y++) {
			if (mymap[z][y] == '*')
				getMapImg(y - 1, 1, z -1, img3.c_str());
			if (mymap[z][y] == '#')
				getMapImg(y - 1, 1, z - 1, img1.c_str());
			if (mymap[z][y] == ' ')
				getMapImg(y - 1, 1, z - 1, img2.c_str());
		}
	}
}

void	Game::getMapImg(int x, int y, int z, const char *img) const
{
	irr::scene::ISceneNode	*block = m_window
		->getM_sceneManager()->addCubeSceneNode();

	if (block) {
			block->setPosition(irr::core::vector3df((x * -264) / 2,
								((-1 * -264) / 2) / 2,
								(z * 264) / 2));
			block->setMaterialTexture(0, m_window->getM_driver()
						  ->getTexture(img));
			block->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			block->setScale(irr::core::vector3df(13.f, 13.f, 13.f));
		}
}
