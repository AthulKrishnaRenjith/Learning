def select_travellers(candidates):
    for first in range(len(candidates)):
        yield [candidates[first]]
    for first in range(len(candidates)):
        for second in range(first+1, len(candidates)):
            yield[candidates[first], candidates[second]]

other_side = { "left" : "right", "right" : "left" }

def safe(state):
    person_side, _ = state
    for side in ['left', 'right']:
        lone_kick = [index for (person, index) in person_side
            if person == 'kick'
            if person_side[person, index] == side
            if person_side['hero', index] != side]
    present_hero = [index for (person, index) in person_side
            if person == 'hero'
            if person_side[person, index] == side]
    if lone_kick and present_hero:
        return False
    return True

class Hero:
    def start(self):
        return {(person, index):"left"
            for person in ['hero', 'kick']
            for index in [1,2,3]}, "left"

    def goal(self, state):
        person_side, boat = state
        return set(person_side[person] for person in person_side) == { "right" }

    def succ(self, state):
        person_side, boat = state
        person_with_boat = [person for person in person_side if person_side[person] == boat]
        for traveller_group in select_travellers(person_with_boat):
            new_side = person_side.copy()
            for traveller in traveller_group:
                new_side[traveller] = other_side[person_side[traveller]]
            new_state = new_side, other_side[boat]
            if safe(new_state):
                yield new_state

class Hero_Token(Hero):
    def token(self, state):
        pairs = sorted(state[0].items())
        return tuple(pairs), state[1]

def depth_first_search(problem, node, visited = set()):
    token = problem.token(node)
    if token in visited: return
    visited = visited.union(set([token]))
    if problem.goal(node): return [node]
    for n_succ in problem.succ(node):
        sol = depth_first_search(problem, n_succ, visited)
        if sol:
            return [node] + sol

h = Hero_Token()
path = depth_first_search(h, h.start())
print(path)


            
