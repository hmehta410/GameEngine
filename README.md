# GameEngine
A Game Engine using an ECS based design

This game engine is a work in progress that has been adapted from the object-oriented engine I developed over three quarters in my master's program at Depaul. The entity component system design was meant as an experiment in creating a more data-oriented engine with an emphasis on modularity. The hope was to create a base engine that could easily be extended independently. For example, if someone wanted to create a collision engine they simply had to create a System and it's corresponding collision Component and add it to the engine. There could even be multiple different attempts at Collision Engines each experimenting with a unique technique. Each attempt would simply need its own System and Component.

This engine currently has Transform, Graphics, Skeletal, and Animation systems. It has three scenes showing off the various systems: the ModelViewer scene shows several different textured models, the BoneAnimationScene shows the animation of a human and teddy skeleton, and the SkinnedAnimation scene extends the BoneAnimationScene by skinning a human and teddy mesh to the skeletal animation.

#User Instructions
This was built using Visual Studio 2013 and should compile in Debug or Release using the solution found at gameengine/GameEngine.sln. It should also be compatable with future versions of visual studio. It was made to run on windows and will likely not compile correctly for unix based systems without some additional work.

There are currently three different Scenes that can be run but they need to be changed by physically going into the game.cpp file and commenting/uncommenting the different lines in the Game::LoadContent() method:

void Game::LoadContent()                                                                                                               
{                                                                                                                                      
  InputMan::Initialize(this->window);                                                                                                
  InputMan::SetWindowSize(info.windowWidth, info.windowHeight);                                                                      
                                                                                                                                      
//this->scene.reset(new ModelViewerScene(this->info.windowWidth, this->info.windowHeight));                                            
  this->scene.reset(new BoneAnimationScene(this->info.windowWidth, this->info.windowHeight));                                            
//this->scene.reset(new SkinnedAnimationScene(this->info.windowWidth, this->info.windowHeight));                                         
}                                                                                                                                        
                                                                                                                                          
Each scene has camera controls for rotating, panning, and zooming by press alt + left-click, middle-click, or right-click. The model viewer scene also has camera switching by pressing the 'c' key.

#Design Considerations

I talked a little bit about this being an ECS engine without explaining what I mean by that. ECS stands for Entity Component System and at least as far as my engine goes an Entity is a container for related Components usually representing some sort of Game Object in a composition manner rather than an inhertance model. Components can be pretty much any instantiable data that is generally acted upon by its corresponding system. I have Transform, Graphics, Animation, and Skeletal components in my engine currently. And finally a System is what does the majority of the work by taking all of its components and processing them. So an animation system will process all animation components at once. This means that a system needs to have access to a pool of all its components. I use a component factory to accompilish this but it is not strictly necessary and is more of an implementation detail. I also give the system full authority on rearranging its components in which ever way it wants, generally with the goal of increased cache efficiency. To allow this I use Component handles which a system will pass out for other systems and entities to be able to access the component opaquely.

Some of the added benefits of my ECS engine is that performance stats/problems can be identified per system and the limits to overall runtime improvements per system can be estimated by replacing a system with a dummy system allowing better usage of optimization efforts. It is also easy to run independent systems in parallel and could be made even easier with a graphical way to order systems.

The are several design artefacts from the original object oriented engine with the most notable being the use of inheritance style linked list style structures: the PCSTree, DList (double linked), and SList (single linked). The requirement was to not use templated classes and the inheritance structure had the added benefit that objects in the PCSTree and DList could be removed in O(1) time. The downsides are quite a few too including no type safety and increased class size from the extra next/prev pointers and virtual table for the destructor. But I decided to keep using them.

Other holdovers from class include the Camera/CameraManager classes used in the current game engine and the Math, File, and Time libraries. In fact, I did not write or even modify the Time library. And finally the custom file formats for meshes, animations, and skeletons are the ones I developed during class. 
