# Puppies

- Loneliness -> Therapists -> Characterize our users.
- App report generation -> Vet -> Scoring the users
- When User sign up -> ID -> Verification
- Rank the users based on how badly the help
- Constraints on how the puppies are stored.
- Service location-based.
- Feedback from users -> Pattern of misbehaviour puppies -> Refrain from assigning them next time round -> Score for the puppies.
- Give suggestions on how to raise the puppies -> So articles on healthcare, meet-ups -> AI tool catered to the users.

- Extension: Give user a preference for kind of dog, allergies, apartment (rent agreements may not allow some kinds of puppies).

# Schema/API Design

Users -> Write Heavy

- user_id
- name
- location
- age
- characterization/score?

Puppies -> Read heavy (Read replicas)

- puppy_id
- breed ?
- location
- charactertization/score
- age

global_request_queue = pq()

request_puppy(user_id, therapist_report, location):
    score = get_user_Score(user_id)
    score = adjusts_score(therapist_report, score)
    global_request_queue.heappush(score, user_id)

resolves_score(global_request_queue):
    if (worker_free && puppies_free(global_request_queue[0][0].location)):

update_queue(time):
    update the score of the user depending on how long they have been waiting

- Collecting feedback from how the puppy's experience was
- Metrics on users.
- Go down every path, ask questions.
- Try spending about 10-12 minutes on a high level design. Be decisive because the time-frame may be smaller. Think about what solution can be deployed as quick as possible if constrained on time.
- Needs to be business oriented and also how you would "decompose" the business down into technical
