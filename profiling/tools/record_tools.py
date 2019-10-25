from .profiler import profile_instance


def generate_dimensions(dimension_generators, current_dim):
    head_generator = dimension_generators[0]

    if len(dimension_generators) == 1:
        yield from ([dim] for dim in head_generator(*current_dim))
    else:
        for elem in head_generator(*current_dim):
            yield from ([elem] + dim for dim in generate_dimensions(dimension_generators[1:], current_dim + [elem]))


def generate_records(dimensions, generators):
    names, dims = zip(*dimensions)
    names2, gens = zip(*generators)

    dimensions = generate_dimensions(dims, [])

    yield names + names2

    for dim in dimensions:
        yield dim + list(map(lambda x: profile_instance(x(*dim)[0], x(*dim)[1], x(*dim)[2]), gens))
