import Vue from 'vue';
import Vuex from 'vuex';
import rp from 'request-promise';

Vue.use(Vuex);

const server = 'http://localhost:5000';

async function getIntensities() {
  const response = await rp.get(`${server}/`, { json: true });
  return response.data.map(intensity => ({
    lat: intensity.latitude,
    lng: intensity.longitude,
    value: intensity.signal_strenght,
  }));
}

export default new Vuex.Store({
  state: {
    intensities: [],
  },
  mutations: {
    addIntensities(state, intensities) {
      state.intensities = intensities;
    },
  },
  actions: {
    async addIntensities({ commit }) {
      const intensities = await getIntensities();
      commit('addIntensities', intensities);
    },
  },
  getters: {
    intensities(state) {
      return state.intensities;
    },
  },
});
