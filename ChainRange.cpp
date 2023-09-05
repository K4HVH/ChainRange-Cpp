template<typename T>
class ChainRange {
public:
    class iterator : public std::iterator<std::input_iterator_tag, T> {
    public:
        explicit iterator(const ChainRange& cr, T value) : cr(cr), value(value) {}

        T operator*() const {
            return value;
        }

        iterator& operator++() {
            value += cr.step;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return (cr.step > 0 && value < other.value) || (cr.step < 0 && value > other.value);
        }

    private:
        const ChainRange& cr;
        T value;
    };

    ChainRange(T start, T stop, T step) : start(start), stop(stop), step(step) {}

    iterator begin() const {
        return iterator(*this, start);
    }

    iterator end() const {
        return iterator(*this, stop);
    }

private:
    T start;
    T stop;
    T step;
};
