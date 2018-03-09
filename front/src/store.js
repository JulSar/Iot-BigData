import Vue from 'vue';
import Vuex from 'vuex';
import rp from 'request-promise';

Vue.use(Vuex);

const server = 'http://51.15.208.245:5000';

async function getIntensities() {
  const response = await rp.get(`${server}/`, { json: true });
  return response.data.map(intensity => ({
    lat: intensity.LATITUDE,
    lng: intensity.LONGITUDE,
    value: intensity.signal_intensity,
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
