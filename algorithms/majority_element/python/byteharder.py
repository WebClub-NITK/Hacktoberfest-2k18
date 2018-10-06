import operator


def majority(list_of_elements):
    try:
        # There is no majority since there are only exactly 2 elements
        # Spec: Majority element will never be more than N/2 times
        if len(list_of_elements) < 2:
            raise ValueError("Not enough elements in the list/array")

        stats = dict()

        for x in list_of_elements:
            total = 0
            for i in xrange(len(list_of_elements)):
                if x == list_of_elements[i]:
                    total += 1
            stats[x] = total

        sorted_stats = sorted(stats.items(), key=operator.itemgetter(1))
        print sorted_stats
        highest_freq = list(sorted_stats[len(sorted_stats)-1])
        print highest_freq

        # The count of highest frequency element does not satisfy 'more than N/2 times'
        if float(highest_freq[1]) <= len(list_of_elements)/2.0:
            return None

        return highest_freq[0]
    except Exception as e:
        return e.args


