# Palantir Virtual Decomp Workshop

These notes are from the Palantir Virtual Decomp workshop held on 29 August.

## Prompt

There are a growing number of people experiencing feelings of loneliness or depression in major cities. A non-profit is attempting to solve this problem by providing a puppy rental service. The non-profit has built out a system for allowing users to sign up for the service, as well as infrastructure to humanely house and transport puppies. However, the non-profit has been having a lot of issues with making sure that the right people are getting puppies. The non-profit has reached out to Palantir to help them solve the allocation problem. The existing system has APIs for retrieving user/puppy information, and now you have to design and implement a system for satisfying user requests for puppies.

## Who are your intended users?

- Medical needs - depression, anxiety, etc - so rescue puppies in general
- Could be old people within retirement homes too, so accessibility is important
- Keeping in touch with accessibility, the service could be catered towards blind users too

## What are the real-world aspects of the problem?

- The users could have preferences of which type of breed they want

Might need a waiting list for more popular pups - probably not that relevant on a smaller scale

- There could be bad actors who could harm the puppies/misuse the platform in another way (not grooming the puppies, ensure frequent vet visits)
- Some of the puppies themselves could grow into aggressive/dangerous dogs.

Both of these can be solved by creating data for each user and puppy. Background checks before giving out the puppies might be needed for safety reasons. This extends to the puppies as well

## What would you choose to prioritize first?

- User puppy matching algo based on demand, urgency, user "score" and puppy "scores"
- User rating and puppy ratings systems as mentioned in the algorithms above
- Health monitoring devices? 

## Are there any tradeoffs to consider?

- Accessibility vs safety: Ensuring regular checkins can get tedious but is important for puppies
- Preference vs Demand: Puppy breeds in more demand? Could solve this by keeping the most in demand puppies for "sale" but not exactly humane.
- Monolith vs microservice: Scalability, downtimes, etc
- Amazon S3 for static files



## What is decomp?

- Open ended problem: Decompose it into manageable parts
- Not code not system design (lmao is it really?)
- Very little code written. Some whiteboarding/notes taking. Some pseudo code at max. 
- Super abstract - define the requirements and define the system

## Why is the comp interview important?

- Decomp is a core engineering skill.
- It's how engineers figure out what system to build.

- Are you able to make progress?
- Are you able to avoid going down rabbit holes? * This is important because you tend to do this
- Can you get yourself un-stuck?
- Are you able to design something that makes sense? Given time period, budget -> ASK THESE THINGS!!
- Are you going to get blocked?

## What are the necessary skills to do well in a decomp interview?

- Don't overengineer your solution: Do they need a massive dashboard
- Pick a goal. Solve and optimize for the goal.
- Problem compartmentalization
- Have great communication, for idea generation.
- Be critical and assess if ideas are good or bad and why?
- Evaluate trade offs: Pros and Cons of making different decisions and justify the choices you make given the solution.
- Think about the user: How technical are they? In what sitatuion will they use the solution.
- Establish structure: Identify the subcomponents of the problem and use them to guide design process.
- Use abstractions
- Start with a minimum viable product -> Progress, not perfection.
- Take feedback, for ex: interviewer might want to talk about concurrency.
- Have a clear mind and clear direction -> no nervousness
- Dont shoot for the stars before the MVP.

## Datasets available

- User information: Name, age, location, rating
- Puppy information: Name, age, location, rating

## Puppy allocation

- More for regular people
- Major cities -> a lot of people -> middle-man -> local hospitals -> Vet (Regular check-ins) -> Partner with them to build more dogs and "scale" (smaller systems)
- Duration per user -> keep track of how you treated dogs you already had.
- Algorithm for users and puppies -> scores you get allotted a puppy.
- Puppies might have "personalities" -> active/laid back
- Location -> Users can set how far they are willing to travel


Users + puppies -> puppy matching service (microservice)
Uber rating system
Minimalize the resources we use -> central system 

Tradeoffs:

Accessibility vs safety
Speed -> waitlisting (categorize how "on the edge someone is") -> Therapists + Vets
Security -> Service might get shut down if things happen to puppy/user -> regulate check-ins
Sustainability -> Puppies will grow old -> Procurement of new puppies? What to do with older dogs? -> Dogs might get separation anxiety

ID Verification is a good point here for background checks

- Tier system -> Your needs 

Diving deep: Puppy match algorithm pseudocode


Users
ID
Name
Age
Location
Score


Puppies
ID
Name 
Age
Location
Score



def set_user_score(id):

def get_user_score(id):

calculate_Score():




def user_requests(user_id):
	get_user_score(id)
	return dog_id

def return_dog(user_id, dog_id):
	set_user_score(user_score)
	set_dog_score()

def user_score():
	filter_location(user)

def puppy_score():
	filter_location(puppy)


def match(user_Score, puppy_Score):

def filter_location(user):
	request(server_url)



