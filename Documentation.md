# Physics Project Documentation

## Classes

### PhysicsGame.cs

Public:

	Name: startup()
	Description: Initializes all variables and adds actors to the scene.
	Type: bool
	
	Name: shutdown()
	Description: Deletes the renderer, scene, and font
	Type: void

	Name: update(float deltaTime)
	Description: Gets and checks input instance, updates scene, and allows players to quit if esc is pressed.
	Type: void

	Name: draw()
	Description: Clears the screen and draws gizmos and fps.
	Type: void

private:

	Name: m_renderer
	Description: The renderer for the scene.
	Type: Renderer2D*

	Name: m_font
	Description: The font of the text.
	Type: Font*

	Name: m_scene
	Description: The scene that everything takes place in.
	Type: PhysicsScene*

### PhysicsObject.cs

public:

	Name: fixedUpdate(glm::vec2 gravity, float timeStep)
	Description: Updates the game at a fixed timestep and utilizes gravity to update shapes every frame.
	Type: void

	Name: draw()
	Description: Draws the shape onto the screen.
	Type: void

	Name: resetPosition
	Description: resets the position of any shape.
	Type: void

	Name: getShapeID()
	Description: Getter to grab the ID of any shape.
	Type: ShapeType

private:

	Name: m_shapeID_
	Description: The ID of the shape.
	Type: ShapeType

### Physics Scene.cs

public:

	Name: addActor(PhysicsObject* actor)
	Description: Adds an actor to the scene.
	Type: void

	Name: removeActor(PhysicsObject* actor)
	Description: Removes an actor from the scene.
	Type: void

	Name: update(float deltaTime)
	Description: Updates the scenes' physics and checks collision each frame.
	Type: void

	Name: draw()
	Description: Calls the actors' draw function.
	Type: void

	Name: setGravity(const glm::vec2 gravity)
	Description: Sets the gravity to be the vec2 passed into this function.
	Type: void

	Name: getGravity()
	Description: Returns the m_gravity vec2.
	Type: glm::vec2

	Name: setTimeStep(const float timeStep)
	Description: Sets the m_timeStep variable to be the float passed into the function.
	Type: void

	Name: getTimeStep()
	Description: Returns the m_timeStep float.
	Type: float

	Name: planeToPlane(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between two planes.
	Type: bool

	Name: planeToSphere(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a plane and a sphere.
	Type: bool

	Name: planeToBox(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a plane and a box.
	Type: bool

	Name: sphereToPlane(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a sphere and a plane.
	Type: bool

	Name: sphereToSphere(PhysicsObject* object1, PhysicsObject* object2)
	Description: checks collision between a sphere and a sphere.
	Type: bool

	Name: sphereToBox(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a sphere and a box.
	Type: bool

	Name: boxToPlane(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a box and a plane.
	Type: bool

	Name: boxToSphere(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a box and a sphere.
	Type: bool

	Name: boxToBox(PhysicsObject* object1, PhysicsObject* object2)
	Description: Checks collision between a box and a box.
	Type: bool


private:

	Name: m_gravity
	Description: The gravity that affects the scene.
	Type: glm::vec2

	Name: m_timeStep
	Description: The time before each step when updating.
	Type: float

	Name: m_actors
	Description: The actors in the scene.
	Type: std::set<PhysicsObject*>

### Plane.cs

public:

	Name: fixedUpdate(glm::vec2 gravity, float timeStep)
	Description: Updates the gravity every frame, also able to be overridden.
	Type: void

	Name: draw()
	Description: Draws the plane when called.
	Type: void

	Name: resolveCollision(RigidBody* other)
	Description: Follows j = ((-(1 + e) * Vrel) dot n) / (n dot (n * (1 / MA + 1 / MB))) to resolve collision.
	Type: void

	Name: getNormal()
	Description: Returns m_normal.
	Type: glm::vec2

	Name: getDistance()
	Description: Returns m_distance.
	Type: float

	Name: getColor()
	Description: Returns m_color.
	Type: glm::vec4

private:

	Name: m_normal
	Description: The planes' normal.
	Type: glm::vec2

	Name: m_distance
	Description: The planes' distance.
	Type: float

	Name: m_color
	Description: The color of the plane.
	Type: glm::vec4

### RigidBody.cs

public:

	Name: fixedUpdate(glm::vec2 gravity, float timeStep)
	Description: Applies gravity and updates the position of the rigidbody at a fixed time step.
	Type: void

	Name: applyForce(glm::vec2 force)
	Description: Applies force by calculating the acceleration via dividing force by the objects mass.
	Type: void

	Name: applyForceToOther(RigidBody* other, glm::vec2 force)
	Description: Calls applyForce for the other object.
	Type: void

	Name: resolveCollision(RigidBody* other)
	Description: Resolves collision using this equation: j = ((-(1 + e) * Vrel) dot n) / (n dot (n * (1 / MA + 1 / MB))).
	Type: void

	Name: getPosition()
	Description: Returns m_position.
	Type: glm::vec2

	Name: getVelocity()
	Description: Returns m_velocity.
	Type: glm::vec2

	Name: getOrientation()
	Description: Returns m_orientation.
	Type: float

	Name: getMass()
	Description: Returns m_mass.
	Type: float

private:

	Name: m_position
	Description: 
	Type: glm::vec2

	Name: m_velocity
	Description: 
	Type: glm::vec2

	Name: m_orientation
	Description: 
	Type: float

	Name: m_mass
	Description: 
	Type: float

### Sphere.cs

public:

	Name: draw()
	Description: Draws a circle on the screen using m_radius and m_color.
	Type: void

	Name: getRadius()
	Description: Returns m_radius.
	Type: float

	Name: getColor()
	Description: Returns m_color.
	Type: glm::vec4

private:

	Name: m_radius
	Description: Returns the radius of the sphere.
	Type: float

	Name: m_color
	Description: Returns the color of the sphere.
	Type:glm::vec4 
